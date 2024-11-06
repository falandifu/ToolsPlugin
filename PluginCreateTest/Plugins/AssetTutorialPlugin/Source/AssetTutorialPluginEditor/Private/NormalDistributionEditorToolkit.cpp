#include "NormalDistributionEditorToolkit.h"
#include "Widgets/Docking/SDockTab.h"
#include "SNormalDistributionWidget.h"
#include "Modules/ModuleManager.h"

void FNormalDistributionEditorToolkit::InitEditor(const TArray<UObject*>& InObjects)
{
	NormalDistribution = Cast<UNormalDistribution>(InObjects[0]);

	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("NormalDistributionEditorLayout")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewSplitter()
				->SetSizeCoefficient(0.6f)
				->SetOrientation(Orient_Horizontal)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.8f)
					->AddTab("NormalDistributionPDFTab", ETabState::OpenedTab)
				)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.2f)
					->AddTab("NormalDistributionDetailsTab", ETabState::OpenedTab)
				)
			)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.4f)
				->AddTab("OutputLog", ETabState::OpenedTab)
			)
		);
	FAssetEditorToolkit::InitAssetEditor(EToolkitMode::Standalone, {}, "NormalDistributionEditor", Layout, true, true, InObjects);
}

void FNormalDistributionEditorToolkit::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);//要注意调用父类的实现，因为它们包含一些逻辑

	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(INVTEXT("Normal Distribution Editor"));

	InTabManager->RegisterTabSpawner("NormalDistributionPDFTab", FOnSpawnTab::CreateLambda([=](const FSpawnTabArgs&)
		{
			return SNew(SDockTab)
				[
					SNew(SNormalDistributionWidget)
						.Mean(this, &FNormalDistributionEditorToolkit::GetMean)
						.StandardDeviation(this, &FNormalDistributionEditorToolkit::GetStandardDeviation)
						.OnMeanChanged(this, &FNormalDistributionEditorToolkit::SetMean)
						.OnStandardDeviationChanged(this, &FNormalDistributionEditorToolkit::SetStandardDeviation)
				];
		}))
		.SetDisplayName(INVTEXT("PDF"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef()); //通过对 RegisterTabSpawner() 返回值进行链接函数调用来设置选项卡的名称和组

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor"); //创建视图
	FDetailsViewArgs DetailsViewArgs;
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	TSharedRef<IDetailsView> DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
	DetailsView->SetObjects(TArray<UObject*>{ NormalDistribution });
	InTabManager->RegisterTabSpawner("NormalDistributionDetailsTab", FOnSpawnTab::CreateLambda([=](const FSpawnTabArgs&)
		{
			return SNew(SDockTab)
				[
					DetailsView
				];
		}))
		.SetDisplayName(INVTEXT("Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef());
}

void FNormalDistributionEditorToolkit::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
	InTabManager->UnregisterTabSpawner("NormalDistributionPDFTab");
	InTabManager->UnregisterTabSpawner("NormalDistributionDetailsTab");
}

float FNormalDistributionEditorToolkit::GetMean() const
{
	return NormalDistribution->Mean;
}

float FNormalDistributionEditorToolkit::GetStandardDeviation() const
{
	return NormalDistribution->StandardDeviation;
}

void FNormalDistributionEditorToolkit::SetMean(float Mean)
{
	NormalDistribution->Modify();//设置器实现中的一个重要细节是对资产对象上的Modify()的调用。这会弄脏资产以便我们可以保存更改并确保事务缓冲区在编辑之前填充对象的状态，从而启用撤消/重做
	NormalDistribution->Mean = Mean;
}

void FNormalDistributionEditorToolkit::SetStandardDeviation(float StandardDeviation)
{
	NormalDistribution->Modify();
	NormalDistribution->StandardDeviation = StandardDeviation;
}
