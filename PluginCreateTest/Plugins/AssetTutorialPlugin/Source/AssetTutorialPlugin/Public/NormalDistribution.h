#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <random>
#include "NormalDistribution.generated.h"

//�����������Զ����ʲ�����

UCLASS(BlueprintType) //��������ͼ�ı�������
class ASSETTUTORIALPLUGIN_API UNormalDistribution : public UObject
{
	GENERATED_BODY()
public:
	UNormalDistribution();

	UPROPERTY(EditAnywhere)
	float Mean;

	UPROPERTY(EditAnywhere)
	float StandardDeviation;

	UFUNCTION(BlueprintCallable)
	float DrawSample();

	UFUNCTION(CallInEditor)
	void LogSample();
private:
	std::mt19937 RandomNumberGenerator;
};
