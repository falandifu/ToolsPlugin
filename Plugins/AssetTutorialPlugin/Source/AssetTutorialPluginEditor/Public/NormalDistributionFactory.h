// Fill out your copyright notice in the Description page of Project Settings.
//Ϊ��UEʶ�𲢴����û�������ʲ�����Ҫ����

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "NormalDistributionFactory.generated.h"

UCLASS()
class UNormalDistributionFactory : public UFactory //UNormalDistributionFactory ȷʵ������ UObject����˵�������ģ��ʱ���� UCLASS ���Զ�ע�ᵽ����
{
	GENERATED_BODY()
public:
	UNormalDistributionFactory();
	UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn);
};
