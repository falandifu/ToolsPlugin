#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <random>
#include "NormalDistribution.generated.h"

//声明并定义自定义资产类型

UCLASS(BlueprintType) //可用于蓝图的变量类型
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
