#pragma once

#include "CoreMinimal.h"
#include "Widgets/SLeafWidget.h"

DECLARE_DELEGATE_OneParam(FOnMeanChanged, float /*NewMean*/) //声明类型为FOnMeanChanged和FOnStandardDeviationChanged的委托
DECLARE_DELEGATE_OneParam(FOnStandardDeviationChanged, float /*NewStandardDeviation*/)
//这些类型的对象可以绑定到其他对象的成员函数，当我们的小部件触发某些事件时，这些对象会做出反应。 通过使用委托，我们的小部件与 UNormalDistribution 实现保持分离

class SNormalDistributionWidget : public SLeafWidget
{
public:
	//利用一些 Slate 宏来使用 Slate 的声明语法来实例化我们的小部件，像 Mean 和 StandardDeviation 这样的Slate属性也可以使用委托对象进行初始化，这样我们就可以在需要时轮询其他对象来获取这些值
	SLATE_BEGIN_ARGS(SNormalDistributionWidget)
		: _Mean(0.5f)
		, _StandardDeviation(0.2f)
		{}
		SLATE_ATTRIBUTE(float, Mean)
		SLATE_ATTRIBUTE(float, StandardDeviation)
		SLATE_EVENT(FOnMeanChanged, OnMeanChanged)
		SLATE_EVENT(FOnStandardDeviationChanged, OnStandardDeviationChanged)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	FVector2D ComputeDesiredSize(float) const override;

	FReply OnMouseButtonDown(const FGeometry& AllottedGeometry, const FPointerEvent& MouseEvent) override;
	FReply OnMouseButtonUp(const FGeometry& AllottedGeometry, const FPointerEvent& MouseEvent) override;
	FReply OnMouseMove(const FGeometry& AllottedGeometry, const FPointerEvent& MouseEvent) override;
private:
	TAttribute<float> Mean;
	TAttribute<float> StandardDeviation;

	FOnMeanChanged OnMeanChanged;
	FOnStandardDeviationChanged OnStandardDeviationChanged;

	FTransform2D GetPointsTransform(const FGeometry& AllottedGeometry) const;
};
