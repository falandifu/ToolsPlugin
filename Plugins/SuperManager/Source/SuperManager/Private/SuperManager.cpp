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
	// 注册内容浏览器资产视图右键菜单扩展
	if (!FModuleManager::Get().IsModuleLoaded("ContentBrowser"))
	{
		FModuleManager::Get().LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	}

	FContentBrowserModule& ContentBrowserModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");

	// 将委托添加到 Content Browser 的 Extender 列表，并保存数组索引以便卸载时移除
	TArray<FContentBrowserMenuExtender_SelectedAssets>& Extenders = ContentBrowserModule.GetAllAssetViewContextMenuExtenders();
	AssetViewExtenderIndex = Extenders.Add(FContentBrowserMenuExtender_SelectedAssets::CreateRaw(this, &FSuperManagerModule::OnExtendContentBrowserAssetSelectionMenu));
}

void FSuperManagerModule::ShutdownModule()
{
	// 卸载扩展
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

// 返回一个 Extender，包含我们要添加的菜单项。SelectedAssets 是右键时的上下文选择。
TSharedRef<FExtender> FSuperManagerModule::OnExtendContentBrowserAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets)
{
	TSharedRef<FExtender> Extender = MakeShared<FExtender>();

	// 在合适的钩点后添加菜单项（字符串钩点可根据需要调整）
	Extender->AddMenuExtension(
		"GetAssetActions", // 钩点名称（常见做法）
		EExtensionHook::After,
		nullptr,
		FMenuExtensionDelegate::CreateLambda([SelectedAssets](FMenuBuilder& MenuBuilder)
			{
				MenuBuilder.AddMenuEntry(
					FText::FromString("Remove Unused Assets (SuperManager)"),
					FText::FromString("删除未被引用的所选资产（使用 SuperManager 工具）"),
					FSlateIcon(),
					FUIAction(
						// 点击时执行的 lambda：直接将选中的 FAssetData 传给 UQuickAssetAction 的方法执行删除逻辑
						FExecuteAction::CreateLambda([SelectedAssets]()
							{
								// 创建 UQuickAssetAction 实例并调用 RemoveUnusedAssets 或自定义方法
								UQuickAssetAction* Utility = NewObject<UQuickAssetAction>(GetTransientPackage(), UQuickAssetAction::StaticClass());
								if (Utility)
								{
									// 尝试调用优先实现的接收 SelectedAssets 的方法（若未实现，可使用现有 RemoveUnusedAssets）
									// 如果 UQuickAssetAction 提供 RemoveUnusedAssetsFrom(const TArray<FAssetData>&)，请使用它。
									// 否则，先将资产设置为当前选中再调用 RemoveUnusedAssets。
									bool bCalled = false;
									// 运行时通过反射检查并调用（编译期保证存在更好）
									if (Utility->GetClass()->FindFunctionByName("RemoveUnusedAssetsFrom"))
									{
										// 需要在 UQuickAssetAction 中实现 RemoveUnusedAssetsFrom 才能直接调用
										struct FDynamicParams { const TArray<FAssetData>* Assets; };
										FDynamicParams Params{ &SelectedAssets };
										Utility->ProcessEvent(Utility->GetClass()->FindFunctionByName("RemoveUnusedAssetsFrom"), &Params);
										bCalled = true;
									}

									if (!bCalled)
									{
										// 退路：把 FAssetData 转为 UObject* 并设置为当前选中，然后调用 RemoveUnusedAssets()
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