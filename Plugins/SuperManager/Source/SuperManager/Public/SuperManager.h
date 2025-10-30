// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Framework/MultiBox/MultiBoxExtender.h"
#include "AssetRegistry/AssetData.h"

/**
 * SuperManager module
 */
class FSuperManagerModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
#pragma region ContentBrowserMenuExtension

	TArray<FString> FolderPathsSelected;

	void InitCBMenuExtention();

	/** 在内容浏览器资产视图右键时返回一个 Extender（添加自定义菜单） */
	TSharedRef<FExtender> OnExtendContentBrowserAssetSelectionMenu(const TArray<FString>& SelectedPaths);

	void AddCBMenuEntry(FMenuBuilder& MenuBuilder);

	void OnDeleteUnusedAssetsButtonClicked();

#pragma endregion

};
