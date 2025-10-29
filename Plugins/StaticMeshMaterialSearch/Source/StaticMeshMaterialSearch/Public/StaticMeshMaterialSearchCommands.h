// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "StaticMeshMaterialSearchStyle.h"

class FStaticMeshMaterialSearchCommands : public TCommands<FStaticMeshMaterialSearchCommands>
{
public:

	FStaticMeshMaterialSearchCommands()
		: TCommands<FStaticMeshMaterialSearchCommands>(TEXT("StaticMeshMaterialSearch"), NSLOCTEXT("Contexts", "StaticMeshMaterialSearch", "StaticMeshMaterialSearch Plugin"), NAME_None, FStaticMeshMaterialSearchStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
