// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuickToolBPLibrary.h"
#include "QuickTool.h"
#include "Kismet/KismetMathLibrary.h"

UQuickToolBPLibrary::UQuickToolBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UQuickToolBPLibrary::SimpleArrayCalculation(float& X, float& Y, int Row, int Index, float RowDistance, float ColumnsDistance, float RowDistanceRandomMin, float RowDistanceRandomMax,
	float CoumnDistanceRandomMin, float CoumnDistanceRandomMax)
{
	X = -(float)(Index / Row * RowDistance) + FMath::FRandRange(RowDistanceRandomMin, RowDistanceRandomMax);
	Y = -(float)(Index % Row * ColumnsDistance) + FMath::FRandRange(CoumnDistanceRandomMin, CoumnDistanceRandomMax);
}

void UQuickToolBPLibrary::CalculateArrayPosition(float& X, float& Y, int32 Rows, int32 Columns, int32 Index, float RowDistance, float ColumnDistance, float RowRandomMin, float RowRandomMax, float ColumnRandomMin, float ColumnRandomMax, FRandomStream PositionStream)
{
	const int32 Seed = PositionStream.RandRange(0, Rows*Columns-Index);
	FRandomStream Stream(Seed);
	UE_LOG(LogTemp, Log, TEXT("%d"), Stream.GetInitialSeed());

	float StandardRowPosition = Index / Columns * RowDistance;
	float RandomRowPostion = Stream.FRandRange ((StandardRowPosition + RowRandomMin), (StandardRowPosition + RowRandomMax));
	float StandardColumnPosition = Index % Columns * ColumnDistance;
	float RandomColumnPosition = Stream.FRandRange ((StandardColumnPosition + ColumnRandomMin), (StandardColumnPosition + ColumnRandomMax));
	X = RandomRowPostion - (((Rows - 1) * RowDistance) / 2);
	Y = RandomColumnPosition - (((Columns - 1) * ColumnDistance) / 2);
}
