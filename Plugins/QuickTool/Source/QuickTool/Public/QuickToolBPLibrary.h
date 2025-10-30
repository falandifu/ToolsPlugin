// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "QuickToolBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UQuickToolBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

#pragma region 阵型
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName ="简易阵列计算", Keywords = "Rows and columns"), Category = "阵型")
	static void SimpleArrayCalculation(float& X, float& Y, int Row, int Index, float RowDistance = 50.f, float ColumnsDistance = 50.f, float RowDistanceRandomMin = 0.f, float RowDistanceRandomMax = 0.f, 
		float CoumnDistanceRandomMin = 0.f, float CoumnDistanceRandomMax = 0.f);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "阵列计算(以Actor为中心)"), Category = "阵型")
    static void CalculateArrayPosition(
        float& X,
        float& Y,
        int32 Rows,
        int32 Columns,
        int32 Index,
        float RowDistance,
        float ColumnDistance,
        float RowRandomMin,
        float RowRandomMax,
        float ColumnRandomMin,
        float ColumnRandomMax,
        FRandomStream PositionStream // Pass by reference to allow state changes
    );

#pragma endregion

};
