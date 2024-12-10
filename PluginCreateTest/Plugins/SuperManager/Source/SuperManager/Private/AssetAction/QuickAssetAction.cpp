// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetAction/QuickAssetAction.h"
#include "EditorUtilityLibrary.h"
#include "EditorAssetLibrary.h"

#include "DebugHeader.h"

void UQuickAssetAction::DuplicateAssets(int32 NumberOfDuplicates)
{
	if (NumberOfDuplicates <= 0)
	{
		ShowMsgDialog(EAppMsgType::Ok, std::move(TEXT("Please Enter A Valid Number")));
		return;
	}

	TArray<FAssetData> SelectedAsstesData = UEditorUtilityLibrary::GetSelectedAssetData();
	int32 Counter = 0;
	
	for (FAssetData SelectedAssetData : SelectedAsstesData)
	{
		for (int32 i = 0; i < NumberOfDuplicates; i++)
		{
			const FString SourceAssetPath = SelectedAssetData.ObjectPath.ToString();
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
		ShowNotifyInfo(std::move(TEXT("Successfully Duplicated " + FString::FromInt(Counter) + " Files")));
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
			ShowMsgDialog(EAppMsgType::Ok, std::move(TEXT("Failed To Find Prefix For Class ") + SelectedObject->GetClass()->GetName()));
			continue;
		}
		FString OldName = SelectedObject->GetName();

		if (OldName.StartsWith(*PrefixFound)) //查找两个字符串是否相同，默认第二个参数不填的情况下忽略大小写，比较长度为PrefixFound字符串的长度
		{
			ShowMsgDialog(EAppMsgType::Ok, std::move(OldName + TEXT(" Already Has Prefix Added")));
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
		ShowNotifyInfo(std::move(TEXT("Successfully Renamed " + FString::FromInt(count) + " Assets")));
}
