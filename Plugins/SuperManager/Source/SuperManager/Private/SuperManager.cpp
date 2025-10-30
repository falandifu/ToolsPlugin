#include "SuperManager.h"
#include "ContentBrowserModule.h"
#include "EditorAssetLibrary.h"
#include "ObjectTools.h"
#include "DebugHeader.h"

#define LOCTEXT_NAMESPACE "FSuperManagerModule"

void FSuperManagerModule::StartupModule()
{
	InitCBMenuExtention();
}

#pragma region ContentBrowserMenuExtension

void FSuperManagerModule::InitCBMenuExtention()
{
	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FContentBrowserMenuExtender_SelectedPaths>& Extenders = ContentBrowserModule.GetAllPathViewContextMenuExtenders();

	FContentBrowserMenuExtender_SelectedPaths CustomCBMenuDelegate;
	CustomCBMenuDelegate.BindRaw(this, &FSuperManagerModule::OnExtendContentBrowserAssetSelectionMenu);

	Extenders.Add(CustomCBMenuDelegate);

}

// 返回一个 Extender，包含我们要添加的菜单项。SelectedAssets 是右键时的上下文选择。
TSharedRef<FExtender> FSuperManagerModule::OnExtendContentBrowserAssetSelectionMenu(const TArray<FString>& SelectedPaths)
{
	TSharedRef<FExtender> Extender = MakeShared<FExtender>();

	if (SelectedPaths.Num() > 0)
	{
		Extender->AddMenuExtension(
			FName("Delete"),
			EExtensionHook::After,
			nullptr,
			FMenuExtensionDelegate::CreateRaw(this, &FSuperManagerModule::AddCBMenuEntry));

		FolderPathsSelected = SelectedPaths;
	}

	return Extender;
}

void FSuperManagerModule::AddCBMenuEntry(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.AddMenuEntry(
		FText::FromString(TEXT("Delete Unused Assets")),
		FText::FromString(TEXT("Safely delete all unused assets under folder")),
		FSlateIcon(),
		FExecuteAction::CreateRaw(this, &FSuperManagerModule::OnDeleteUnusedAssetsButtonClicked));
			
}

//实现删除文件夹中未使用资源的功能
void FSuperManagerModule::OnDeleteUnusedAssetsButtonClicked()
{
	if (FolderPathsSelected.Num() > 1)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok, TEXT("只能选择一个文件夹删除未使用的资源"));
		return;
	}

	TArray<FString>AssetsPathNames = UEditorAssetLibrary::ListAssets(FolderPathsSelected[0]);
	if (AssetsPathNames.Num() == 0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok, TEXT("在所选文件夹中未找到资源"));
		return;
	}

	FString Message = FString::Printf(TEXT("总共 %d 个文件\n确定接受吗?"), AssetsPathNames.Num());
	//拼接中文字符最好将文件编码类型转为UTF-8
	EAppReturnType::Type ConfirmResult = DebugHeader::ShowMsgDialog(EAppMsgType::OkCancel, Message);

	if (ConfirmResult == EAppReturnType::Cancel) return;

	TArray<FAssetData> UnusedAssetsDataArray;

	for (const FString& AssetPathName : AssetsPathNames)
	{
		if (AssetPathName.Contains(TEXT("Developers")) || AssetPathName.Contains(TEXT("Collections")))
		{
			continue;
		}

		if (!UEditorAssetLibrary::DoesAssetExist(AssetPathName)) continue;

		TArray<FString> AssetReferencers =
		UEditorAssetLibrary::FindPackageReferencersForAsset(AssetPathName);

		if (AssetReferencers.Num() == 0)
		{
			const FAssetData UnusedAssetData = UEditorAssetLibrary::FindAssetData(AssetPathName);
			UnusedAssetsDataArray.Add(UnusedAssetData);
		}
	}

	if (UnusedAssetsDataArray.Num() > 0)
	{
		ObjectTools::DeleteAssets(UnusedAssetsDataArray);
	}
	else
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok, TEXT("在所选文件夹中未找到资源"));
	}

}

#pragma endregion

void FSuperManagerModule::ShutdownModule()
{
	// 卸载扩展
}

IMPLEMENT_MODULE(FSuperManagerModule, SuperManager)