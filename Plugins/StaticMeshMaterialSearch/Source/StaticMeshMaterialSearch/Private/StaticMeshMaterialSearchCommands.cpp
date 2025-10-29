// Copyright Epic Games, Inc. All Rights Reserved.

#include "StaticMeshMaterialSearchCommands.h"

#define LOCTEXT_NAMESPACE "FStaticMeshMaterialSearchModule"

void FStaticMeshMaterialSearchCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "StaticMeshMaterialSearch", "Execute StaticMeshMaterialSearch action", EUserInterfaceActionType::Button, FInputChord(EKeys::W, EModifierKey::Control));
}

#undef LOCTEXT_NAMESPACE
