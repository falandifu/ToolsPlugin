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
	/** 索引到 Content Browser 的 Asset View Extenders 数组，用于移除时使用 */
	int32 AssetViewExtenderIndex = INDEX_NONE;

	/** 在内容浏览器资产视图右键时返回一个 Extender（添加自定义菜单） */
	TSharedRef<FExtender> OnExtendContentBrowserAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets);
};
