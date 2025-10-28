#pragma once

#include "CoreMinimal.h"
#include "NormalDistribution.h"
#include "Toolkits/AssetEditorToolkit.h"

class FNormalDistributionEditorToolkit : public FAssetEditorToolkit //该类为开发资源编辑器的基本类
{
public:
	void InitEditor(const TArray<UObject*>& InObjects);

	void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;
	void UnregisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;

	FName GetToolkitFName() const override { return "NormalDistributionEditor"; }
	FText GetBaseToolkitName() const override { return INVTEXT("Normal Distribution Editor"); }
	FString GetWorldCentricTabPrefix() const override { return "Normal Distribution "; }
	FLinearColor GetWorldCentricTabColorScale() const override { return {}; }

	float GetMean() const;
	float GetStandardDeviation() const;
	void SetMean(float Mean);
	void SetStandardDeviation(float StandardDeviation);
private:
	UNormalDistribution* NormalDistribution; //一般来说，这样的指针是危险的，因为垃圾收集器可能会在我们不注意的情况下销毁 UObject 派生类的该对象。 但在这种情况下，可以安全地假设只要编辑器打开，资产就会保留在内存中，并且如果在编辑时删除资产，编辑器会自动关闭
};
