#include "NormalDistributionActions.h"
#include "NormalDistribution.h"
#include "NormalDistributionEditorToolkit.h"

UClass* FNormalDistributionAssetTypeActions::GetSupportedClass() const
{
    return UNormalDistribution::StaticClass();
}

FText FNormalDistributionAssetTypeActions::GetName() const
{
    return INVTEXT("Normal Distribution");
}

FColor FNormalDistributionAssetTypeActions::GetTypeColor() const
{
    return FColor::Cyan;
}

uint32 FNormalDistributionAssetTypeActions::GetCategories()
{
    return EAssetTypeCategories::Misc;
}

void FNormalDistributionAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
    MakeShared<FNormalDistributionEditorToolkit>()->InitEditor(InObjects);/*MakeShared() 返回的临时 TSharedRef。 
    创建的 FNormalDistributionEditorToolkit 不会在 TSharedRef 超出范围时被销毁，因为它通过 FAssetEditorToolkit 从 TSharedFromThis 派生，并且当它完全初始化时，它会在其他地方引用*/
}
