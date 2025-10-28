#include "NormalDistributionFactory.h"
#include "NormalDistribution.h"

UNormalDistributionFactory::UNormalDistributionFactory()
{
    SupportedClass = UNormalDistribution::StaticClass();
    bCreateNew = true; //在构造函数中将 bCreateNew 设置为 true 将允许我们在内容浏览器中创建我们类型的资源
}

UObject* UNormalDistributionFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
    return NewObject<UNormalDistribution>(InParent, Class, Name, Flags, Context);
}
