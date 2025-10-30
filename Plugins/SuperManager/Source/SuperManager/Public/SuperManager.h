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

	/** ������������ʲ���ͼ�Ҽ�ʱ����һ�� Extender������Զ���˵��� */
	TSharedRef<FExtender> OnExtendContentBrowserAssetSelectionMenu(const TArray<FString>& SelectedPaths);

	void AddCBMenuEntry(FMenuBuilder& MenuBuilder);

	void OnDeleteUnusedAssetsButtonClicked();

#pragma endregion

};
