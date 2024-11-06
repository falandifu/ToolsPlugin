#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class FNormalDistributionAssetTypeActions : public FAssetTypeActions_Base
{
public:
	UClass* GetSupportedClass() const override; //返回您的资产类(UUserDefinedAsset)
	FText GetName() const override; //返回编辑器中显示的资产类型名称
	FColor GetTypeColor() const override; //返回编辑器中显示的资产类型颜色
	uint32 GetCategories() override; //创建资产时，编辑器中显示的类别，您可以定义自定义类别位和返回
	void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor) override; //用于打开资产编辑器的入口
};
