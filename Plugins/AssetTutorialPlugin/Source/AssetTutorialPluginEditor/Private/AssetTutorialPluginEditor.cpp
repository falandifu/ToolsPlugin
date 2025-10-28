#include "AssetTutorialPluginEditor.h"

void FAssetTutorialPluginEditorModule::StartupModule() //注册资产类型
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	NormalDistributionAssetTypeActions = MakeShared<FNormalDistributionAssetTypeActions>();
	FAssetToolsModule::GetModule().Get().RegisterAssetTypeActions(NormalDistributionAssetTypeActions.ToSharedRef());
}

void FAssetTutorialPluginEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if (!FModuleManager::Get().IsModuleLoaded("AssetTools")) 
		return;
	FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(NormalDistributionAssetTypeActions.ToSharedRef());
}
	
IMPLEMENT_MODULE(FAssetTutorialPluginEditorModule, AssetTutorialPluginEditor)