// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SuperManager/Public/AssetAction/QuickAssetAction.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuickAssetAction() {}
// Cross Module References
	BLUTILITY_API UClass* Z_Construct_UClass_UAssetActionUtility();
	SUPERMANAGER_API UClass* Z_Construct_UClass_UQuickAssetAction();
	SUPERMANAGER_API UClass* Z_Construct_UClass_UQuickAssetAction_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SuperManager();
// End Cross Module References
	DEFINE_FUNCTION(UQuickAssetAction::execAddPrefixs)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddPrefixs();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UQuickAssetAction::execDuplicateAssets)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_NumberOfDuplicates);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DuplicateAssets(Z_Param_NumberOfDuplicates);
		P_NATIVE_END;
	}
	void UQuickAssetAction::StaticRegisterNativesUQuickAssetAction()
	{
		UClass* Class = UQuickAssetAction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddPrefixs", &UQuickAssetAction::execAddPrefixs },
			{ "DuplicateAssets", &UQuickAssetAction::execDuplicateAssets },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuickAssetAction_AddPrefixs_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuickAssetAction_AddPrefixs_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickAssetAction.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickAssetAction_AddPrefixs_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickAssetAction, nullptr, "AddPrefixs", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuickAssetAction_AddPrefixs_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickAssetAction_AddPrefixs_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuickAssetAction_AddPrefixs()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickAssetAction_AddPrefixs_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics
	{
		struct QuickAssetAction_eventDuplicateAssets_Parms
		{
			int32 NumberOfDuplicates;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_NumberOfDuplicates;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::NewProp_NumberOfDuplicates = { "NumberOfDuplicates", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(QuickAssetAction_eventDuplicateAssets_Parms, NumberOfDuplicates), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::NewProp_NumberOfDuplicates,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickAssetAction.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickAssetAction, nullptr, "DuplicateAssets", nullptr, nullptr, sizeof(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::QuickAssetAction_eventDuplicateAssets_Parms), Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuickAssetAction);
	UClass* Z_Construct_UClass_UQuickAssetAction_NoRegister()
	{
		return UQuickAssetAction::StaticClass();
	}
	struct Z_Construct_UClass_UQuickAssetAction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuickAssetAction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAssetActionUtility,
		(UObject* (*)())Z_Construct_UPackage__Script_SuperManager,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuickAssetAction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuickAssetAction_AddPrefixs, "AddPrefixs" }, // 2257628215
		{ &Z_Construct_UFunction_UQuickAssetAction_DuplicateAssets, "DuplicateAssets" }, // 1017636296
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuickAssetAction_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "AssetAction/QuickAssetAction.h" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickAssetAction.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuickAssetAction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuickAssetAction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuickAssetAction_Statics::ClassParams = {
		&UQuickAssetAction::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UQuickAssetAction_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UQuickAssetAction_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UQuickAssetAction()
	{
		if (!Z_Registration_Info_UClass_UQuickAssetAction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuickAssetAction.OuterSingleton, Z_Construct_UClass_UQuickAssetAction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UQuickAssetAction.OuterSingleton;
	}
	template<> SUPERMANAGER_API UClass* StaticClass<UQuickAssetAction>()
	{
		return UQuickAssetAction::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuickAssetAction);
	UQuickAssetAction::~UQuickAssetAction() {}
	struct Z_CompiledInDeferFile_FID_PluginCreateTest_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickAssetAction_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginCreateTest_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickAssetAction_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UQuickAssetAction, UQuickAssetAction::StaticClass, TEXT("UQuickAssetAction"), &Z_Registration_Info_UClass_UQuickAssetAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuickAssetAction), 3552271767U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginCreateTest_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickAssetAction_h_308029672(TEXT("/Script/SuperManager"),
		Z_CompiledInDeferFile_FID_PluginCreateTest_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickAssetAction_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginCreateTest_Plugins_SuperManager_Source_SuperManager_Public_AssetAction_QuickAssetAction_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
