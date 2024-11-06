// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AssetTutorialPlugin/Public/NormalDistribution.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNormalDistribution() {}
// Cross Module References
	ASSETTUTORIALPLUGIN_API UClass* Z_Construct_UClass_UNormalDistribution();
	ASSETTUTORIALPLUGIN_API UClass* Z_Construct_UClass_UNormalDistribution_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_AssetTutorialPlugin();
// End Cross Module References
	DEFINE_FUNCTION(UNormalDistribution::execLogSample)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LogSample();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UNormalDistribution::execDrawSample)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->DrawSample();
		P_NATIVE_END;
	}
	void UNormalDistribution::StaticRegisterNativesUNormalDistribution()
	{
		UClass* Class = UNormalDistribution::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DrawSample", &UNormalDistribution::execDrawSample },
			{ "LogSample", &UNormalDistribution::execLogSample },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UNormalDistribution_DrawSample_Statics
	{
		struct NormalDistribution_eventDrawSample_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UNormalDistribution_DrawSample_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(NormalDistribution_eventDrawSample_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNormalDistribution_DrawSample_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNormalDistribution_DrawSample_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UNormalDistribution_DrawSample_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/NormalDistribution.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNormalDistribution_DrawSample_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UNormalDistribution, nullptr, "DrawSample", nullptr, nullptr, sizeof(Z_Construct_UFunction_UNormalDistribution_DrawSample_Statics::NormalDistribution_eventDrawSample_Parms), Z_Construct_UFunction_UNormalDistribution_DrawSample_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNormalDistribution_DrawSample_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UNormalDistribution_DrawSample_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UNormalDistribution_DrawSample_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UNormalDistribution_DrawSample()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNormalDistribution_DrawSample_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UNormalDistribution_LogSample_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UNormalDistribution_LogSample_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/NormalDistribution.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNormalDistribution_LogSample_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UNormalDistribution, nullptr, "LogSample", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UNormalDistribution_LogSample_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UNormalDistribution_LogSample_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UNormalDistribution_LogSample()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNormalDistribution_LogSample_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNormalDistribution);
	UClass* Z_Construct_UClass_UNormalDistribution_NoRegister()
	{
		return UNormalDistribution::StaticClass();
	}
	struct Z_Construct_UClass_UNormalDistribution_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mean_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Mean;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StandardDeviation_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_StandardDeviation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNormalDistribution_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_AssetTutorialPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UNormalDistribution_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UNormalDistribution_DrawSample, "DrawSample" }, // 1279710435
		{ &Z_Construct_UFunction_UNormalDistribution_LogSample, "LogSample" }, // 379497876
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNormalDistribution_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "//\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd4\xb6\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb2\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
		{ "IncludePath", "NormalDistribution.h" },
		{ "ModuleRelativePath", "Public/NormalDistribution.h" },
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd4\xb6\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb2\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNormalDistribution_Statics::NewProp_Mean_MetaData[] = {
		{ "Category", "NormalDistribution" },
		{ "ModuleRelativePath", "Public/NormalDistribution.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UNormalDistribution_Statics::NewProp_Mean = { "Mean", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UNormalDistribution, Mean), METADATA_PARAMS(Z_Construct_UClass_UNormalDistribution_Statics::NewProp_Mean_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UNormalDistribution_Statics::NewProp_Mean_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNormalDistribution_Statics::NewProp_StandardDeviation_MetaData[] = {
		{ "Category", "NormalDistribution" },
		{ "ModuleRelativePath", "Public/NormalDistribution.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UNormalDistribution_Statics::NewProp_StandardDeviation = { "StandardDeviation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UNormalDistribution, StandardDeviation), METADATA_PARAMS(Z_Construct_UClass_UNormalDistribution_Statics::NewProp_StandardDeviation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UNormalDistribution_Statics::NewProp_StandardDeviation_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNormalDistribution_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNormalDistribution_Statics::NewProp_Mean,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNormalDistribution_Statics::NewProp_StandardDeviation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNormalDistribution_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNormalDistribution>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNormalDistribution_Statics::ClassParams = {
		&UNormalDistribution::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UNormalDistribution_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UNormalDistribution_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UNormalDistribution_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UNormalDistribution_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UNormalDistribution()
	{
		if (!Z_Registration_Info_UClass_UNormalDistribution.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNormalDistribution.OuterSingleton, Z_Construct_UClass_UNormalDistribution_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNormalDistribution.OuterSingleton;
	}
	template<> ASSETTUTORIALPLUGIN_API UClass* StaticClass<UNormalDistribution>()
	{
		return UNormalDistribution::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNormalDistribution);
	UNormalDistribution::~UNormalDistribution() {}
	struct Z_CompiledInDeferFile_FID_PluginCreateTest_Plugins_AssetTutorialPlugin_Source_AssetTutorialPlugin_Public_NormalDistribution_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginCreateTest_Plugins_AssetTutorialPlugin_Source_AssetTutorialPlugin_Public_NormalDistribution_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNormalDistribution, UNormalDistribution::StaticClass, TEXT("UNormalDistribution"), &Z_Registration_Info_UClass_UNormalDistribution, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNormalDistribution), 1303747352U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginCreateTest_Plugins_AssetTutorialPlugin_Source_AssetTutorialPlugin_Public_NormalDistribution_h_3055693185(TEXT("/Script/AssetTutorialPlugin"),
		Z_CompiledInDeferFile_FID_PluginCreateTest_Plugins_AssetTutorialPlugin_Source_AssetTutorialPlugin_Public_NormalDistribution_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginCreateTest_Plugins_AssetTutorialPlugin_Source_AssetTutorialPlugin_Public_NormalDistribution_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
