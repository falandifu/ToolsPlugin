// Fill out your copyright notice in the Description page of Project Settings.
//为让UE识别并创建用户定义的资产所需要的类

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "NormalDistributionFactory.generated.h"

UCLASS()
class UNormalDistributionFactory : public UFactory //UNormalDistributionFactory 确实派生自 UObject，因此当加载其模块时，其 UCLASS 会自动注册到引擎
{
	GENERATED_BODY()
public:
	UNormalDistributionFactory();
	UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn);
};
