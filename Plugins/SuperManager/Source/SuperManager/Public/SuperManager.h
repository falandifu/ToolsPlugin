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
	/** ������ Content Browser �� Asset View Extenders ���飬�����Ƴ�ʱʹ�� */
	int32 AssetViewExtenderIndex = INDEX_NONE;

	/** ������������ʲ���ͼ�Ҽ�ʱ����һ�� Extender������Զ���˵��� */
	TSharedRef<FExtender> OnExtendContentBrowserAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets);
};
