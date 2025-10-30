// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetAction/QuickAssetAction.h"
#include "EditorUtilityLibrary.h"
#include "EditorAssetLibrary.h"
#include "ObjectTools.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetToolsModule.h"

#include "DebugHeader.h"

void UQuickAssetAction::DuplicateAssets(int32 NumberOfDuplicates)
{
	if (NumberOfDuplicates <= 0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok, TEXT("Please Enter A Valid Number"));
		return;
	}

	TArray<FAssetData> SelectedAsstesData = UEditorUtilityLibrary::GetSelectedAssetData();
	int32 Counter = 0;
	
	for (FAssetData SelectedAssetData : SelectedAsstesData)
	{
		for (int32 i = 0; i < NumberOfDuplicates; i++)
		{
			const FString SourceAssetPath = SelectedAssetData.GetObjectPathString();
			const FString NewDuplicatedAssetName = SelectedAssetData.AssetName.ToString() + TEXT("_") + FString::FromInt(i+1);
			const FString NewPathName = FPaths::Combine(SelectedAssetData.PackagePath.ToString(), NewDuplicatedAssetName);

			if (UEditorAssetLibrary::DuplicateAsset(SourceAssetPath, NewPathName))
			{
				UEditorAssetLibrary::SaveAsset(NewPathName, false);
				Counter++;
			}
		}
	}
	if (Counter > 0)
	{
		//Print(std::move(FColor::Green), std::move(TEXT("Successfully Duplicated " + FString::FromInt(Counter) + "Files")));
		DebugHeader::ShowNotifyInfo(TEXT("Successfully Duplicated " + FString::FromInt(Counter) + " Files"));
	}
}

void UQuickAssetAction::AddPrefixs()
{
	TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();
	uint32 count = 0;

	for (UObject* SelectedObject : SelectedObjects)
	{
		if (!SelectedObject)
			continue;
		FString* PrefixFound = PrefixsMap.Find(SelectedObject->GetClass());

		if (!PrefixFound || PrefixFound->IsEmpty())
		{
			DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("Failed To Find Prefix For Class ") + SelectedObject->GetClass()->GetName());
			continue;
		}
		FString OldName = SelectedObject->GetName();

		if (OldName.StartsWith(*PrefixFound)) //查找两个字符串是否相同，默认第二个参数不填的情况下忽略大小写，比较长度为PrefixFound字符串的长度
		{
			DebugHeader::ShowMsgDialog(EAppMsgType::Ok, OldName + TEXT(" Already Has Prefix Added"));
			continue;
		}

		if (SelectedObject->IsA<UMaterialInstanceConstant>())
		{
			OldName.RemoveFromStart(TEXT("M_"));
			OldName.RemoveFromEnd(TEXT("_inst"));
		}

		FString NewNameWithPrefix = *PrefixFound + OldName;
		UEditorUtilityLibrary::RenameAsset(SelectedObject, NewNameWithPrefix);
		count++;
	}

	if(count>0)
		DebugHeader::ShowNotifyInfo(TEXT("Successfully Renamed " + FString::FromInt(count) + " Assets"));
}

void UQuickAssetAction::RemoveUnusedAssets()
{
	TArray<FAssetData> SelectAssetsData = UEditorUtilityLibrary::GetSelectedAssetData();
	TArray<FAssetData> UnuesdAssetsData;

	FixUpRedirectors();

	for (const FAssetData& SelectAssetData : SelectAssetsData)
	{
		TArray<FString> AssetReferencer =
		UEditorAssetLibrary::FindPackageReferencersForAsset(SelectAssetData.GetObjectPathString());

		if (AssetReferencer.Num()==0)
		{
			UnuesdAssetsData.Add(SelectAssetData);
		}
	}

	if (UnuesdAssetsData.Num()==0)
	{
		DebugHeader::ShowMsgDialog(EAppMsgType::Ok,TEXT("No unuesd asset found among selected assets"),false);
		return;
	}

	int32 NumberOfUnuesdAsset = ObjectTools::DeleteAssets(UnuesdAssetsData);
	if (NumberOfUnuesdAsset == 0) return;
	DebugHeader::ShowNotifyInfo(TEXT("Successfully delete") + FString::FromInt(NumberOfUnuesdAsset) + TEXT("unuesd asset"));
}

void UQuickAssetAction::FixUpRedirectors()
{
	TArray<UObjectRedirector*> RedirectorToFixArray;
	TArray<UObject*> LoadedRedirectorObjects; // 保持 UObject 引用，防止 GC 或被释放

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::Get().LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

	TArray<FAssetData> OutRedirectors;
	FARFilter Filter;
	Filter.bRecursivePaths = true;
	// 使用类路径名而不是硬编码字符串
	Filter.ClassPaths.Emplace(UObjectRedirector::StaticClass()->GetClassPathName());
	Filter.PackagePaths.Emplace(TEXT("/Game"));

	AssetRegistryModule.Get().GetAssets(Filter, OutRedirectors);

	for (const FAssetData& OutRedirector : OutRedirectors)
	{
		// 通过 GetAsset() 加载并保存 UObject 引用到数组，保证其在后续处理期间存活
		if (UObject* AssetObj = OutRedirector.GetAsset())
		{
			LoadedRedirectorObjects.Add(AssetObj);
			if (UObjectRedirector* RedirectorToFix = Cast<UObjectRedirector>(AssetObj))
			{
				RedirectorToFixArray.Add(RedirectorToFix);
			}
		}
	}

	if (RedirectorToFixArray.Num() == 0)
	{
		// 没有要修复的重定向器，直接返回
		return;
	}

	// 确保 AssetTools 模块存在后再调用
	FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
	AssetToolsModule.Get().FixupReferencers(RedirectorToFixArray);
}
