#pragma once

#include "CoreMinimal.h"
#include "NormalDistribution.h"
#include "Toolkits/AssetEditorToolkit.h"

class FNormalDistributionEditorToolkit : public FAssetEditorToolkit //����Ϊ������Դ�༭���Ļ�����
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
	UNormalDistribution* NormalDistribution; //һ����˵��������ָ����Σ�յģ���Ϊ�����ռ������ܻ������ǲ�ע������������ UObject ������ĸö��� ������������£����԰�ȫ�ؼ���ֻҪ�༭���򿪣��ʲ��ͻᱣ�����ڴ��У���������ڱ༭ʱɾ���ʲ����༭�����Զ��ر�
};
