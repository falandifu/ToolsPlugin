// Copyright Epic Games, Inc. All Rights Reserved.

#include "StaticMeshMaterialSearch.h"
#include "StaticMeshMaterialSearchStyle.h"
#include "StaticMeshMaterialSearchCommands.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "StaticMeshEditorModule.h"


static const FName StaticMeshMaterialSearchTabName("StaticMeshMaterialSearch");

#define LOCTEXT_NAMESPACE "FStaticMeshMaterialSearchModule"

void FStaticMeshMaterialSearchModule::StartupModule()
{
	FStaticMeshMaterialSearchStyle::Initialize();
	FStaticMeshMaterialSearchStyle::ReloadTextures();

	FStaticMeshMaterialSearchCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FStaticMeshMaterialSearchCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FStaticMeshMaterialSearchModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FStaticMeshMaterialSearchModule::RegisterMenus));
}

void FStaticMeshMaterialSearchModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FStaticMeshMaterialSearchStyle::Shutdown();

	FStaticMeshMaterialSearchCommands::Unregister();
}

void FStaticMeshMaterialSearchModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FStaticMeshMaterialSearchModule::PluginButtonClicked()")),
							FText::FromString(TEXT("StaticMeshMaterialSearch.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FStaticMeshMaterialSearchModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FStaticMeshMaterialSearchCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FStaticMeshMaterialSearchCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FStaticMeshMaterialSearchModule, StaticMeshMaterialSearch)