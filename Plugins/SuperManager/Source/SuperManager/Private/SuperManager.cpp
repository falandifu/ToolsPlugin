#include "SuperManager.h"
#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/MultiBox/MultiBoxExtender.h"
#include "EditorUtilityLibrary.h"
#include "AssetRegistry/AssetData.h"
#include "AssetAction/QuickAssetAction.h"
#include "Modules/ModuleManager.h"

void FSuperManagerModule::StartupModule()
{
	// ע������������ʲ���ͼ�Ҽ��˵���չ
	if (!FModuleManager::Get().IsModuleLoaded("ContentBrowser"))
	{
		FModuleManager::Get().LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	}

	FContentBrowserModule& ContentBrowserModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");

	// ��ί����ӵ� Content Browser �� Extender �б����������������Ա�ж��ʱ�Ƴ�
	TArray<FContentBrowserMenuExtender_SelectedAssets>& Extenders = ContentBrowserModule.GetAllAssetViewContextMenuExtenders();
	AssetViewExtenderIndex = Extenders.Add(FContentBrowserMenuExtender_SelectedAssets::CreateRaw(this, &FSuperManagerModule::OnExtendContentBrowserAssetSelectionMenu));
}

void FSuperManagerModule::ShutdownModule()
{
	// ж����չ
	if (FModuleManager::Get().IsModuleLoaded("ContentBrowser"))
	{
		FContentBrowserModule& ContentBrowserModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");
		TArray<FContentBrowserMenuExtender_SelectedAssets>& Extenders = ContentBrowserModule.GetAllAssetViewContextMenuExtenders();
		if (Extenders.IsValidIndex(AssetViewExtenderIndex))
		{
			Extenders.RemoveAt(AssetViewExtenderIndex);
			AssetViewExtenderIndex = INDEX_NONE;
		}
	}
}

// ����һ�� Extender����������Ҫ��ӵĲ˵��SelectedAssets ���Ҽ�ʱ��������ѡ��
TSharedRef<FExtender> FSuperManagerModule::OnExtendContentBrowserAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets)
{
	TSharedRef<FExtender> Extender = MakeShared<FExtender>();

	// �ں��ʵĹ������Ӳ˵���ַ�������ɸ�����Ҫ������
	Extender->AddMenuExtension(
		"GetAssetActions", // �������ƣ�����������
		EExtensionHook::After,
		nullptr,
		FMenuExtensionDelegate::CreateLambda([SelectedAssets](FMenuBuilder& MenuBuilder)
			{
				MenuBuilder.AddMenuEntry(
					FText::FromString("Remove Unused Assets (SuperManager)"),
					FText::FromString("ɾ��δ�����õ���ѡ�ʲ���ʹ�� SuperManager ���ߣ�"),
					FSlateIcon(),
					FUIAction(
						// ���ʱִ�е� lambda��ֱ�ӽ�ѡ�е� FAssetData ���� UQuickAssetAction �ķ���ִ��ɾ���߼�
						FExecuteAction::CreateLambda([SelectedAssets]()
							{
								// ���� UQuickAssetAction ʵ�������� RemoveUnusedAssets ���Զ��巽��
								UQuickAssetAction* Utility = NewObject<UQuickAssetAction>(GetTransientPackage(), UQuickAssetAction::StaticClass());
								if (Utility)
								{
									// ���Ե�������ʵ�ֵĽ��� SelectedAssets �ķ�������δʵ�֣���ʹ������ RemoveUnusedAssets��
									// ��� UQuickAssetAction �ṩ RemoveUnusedAssetsFrom(const TArray<FAssetData>&)����ʹ������
									// �����Ƚ��ʲ�����Ϊ��ǰѡ���ٵ��� RemoveUnusedAssets��
									bool bCalled = false;
									// ����ʱͨ�������鲢���ã������ڱ�֤���ڸ��ã�
									if (Utility->GetClass()->FindFunctionByName("RemoveUnusedAssetsFrom"))
									{
										// ��Ҫ�� UQuickAssetAction ��ʵ�� RemoveUnusedAssetsFrom ����ֱ�ӵ���
										struct FDynamicParams { const TArray<FAssetData>* Assets; };
										FDynamicParams Params{ &SelectedAssets };
										Utility->ProcessEvent(Utility->GetClass()->FindFunctionByName("RemoveUnusedAssetsFrom"), &Params);
										bCalled = true;
									}

									if (!bCalled)
									{
										// ��·���� FAssetData תΪ UObject* ������Ϊ��ǰѡ�У�Ȼ����� RemoveUnusedAssets()
										TArray<UObject*> ObjectsToSelect;
										ObjectsToSelect.Reserve(SelectedAssets.Num());
										for (const FAssetData& AD : SelectedAssets)
										{
											if (UObject* Obj = AD.GetAsset())
											{
												ObjectsToSelect.Add(Obj);
											}
										}

										if (ObjectsToSelect.Num() > 0)
										{
											UEditorUtilityLibrary::SetSelectedAssets(ObjectsToSelect);
										}

										Utility->RemoveUnusedAssets();
									}
								}
							})
					)
				);
			})
	);

	return Extender;
}

IMPLEMENT_MODULE(FSuperManagerModule, SuperManager)