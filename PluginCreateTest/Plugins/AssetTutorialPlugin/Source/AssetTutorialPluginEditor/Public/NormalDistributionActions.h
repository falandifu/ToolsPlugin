#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class FNormalDistributionAssetTypeActions : public FAssetTypeActions_Base
{
public:
	UClass* GetSupportedClass() const override; //���������ʲ���(UUserDefinedAsset)
	FText GetName() const override; //���ر༭������ʾ���ʲ���������
	FColor GetTypeColor() const override; //���ر༭������ʾ���ʲ�������ɫ
	uint32 GetCategories() override; //�����ʲ�ʱ���༭������ʾ����������Զ����Զ������λ�ͷ���
	void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor) override; //���ڴ��ʲ��༭�������
};
