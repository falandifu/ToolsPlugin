# ToolsPlugin
自用 UE 工具插件集合（UE5.3）。

本仓库包含一个示例项目与两个 Editor 插件：`AssetTutorialPlugin` 与 `SuperManager`，用于提升资产批处理与自定义资产类型编辑体验。

## 目录结构
- `Source/PluginCreateTest/`：示例项目源码。
- `Plugins/AssetTutorialPlugin/`：自定义资产与编辑器工具集。
- `Plugins/SuperManager/`：资产批处理工具（Editor Utility）。

## 插件一：AssetTutorialPlugin
提供“正态分布（NormalDistribution）”自定义资产类型及其编辑器：
- `UNormalDistribution` 资产（`NormalDistribution.h/.cpp`）
  - 字段：`Mean`（均值，默认 0.5）、`StandardDeviation`（标准差，默认 0.2）
  - 方法：
    - `DrawSample()`：基于 `std::normal_distribution` 抽样。
    - `LogSample()`（在编辑器中可调用）：打印一次抽样结果到日志。
- 工厂 `UNormalDistributionFactory`：在内容浏览器中创建该资产。
- 自定义编辑器 `FNormalDistributionEditorToolkit`：
  - 左侧标签页“PDF”内置 `SNormalDistributionWidget`，可视化正态分布曲线，并通过拖拽交互调整 `Mean` 与 `StandardDeviation`。
  - 右侧“Details”标签页显示资产详情面板。
- Slate 控件 `SNormalDistributionWidget`：
  - 实时绘制 PDF 曲线（512 采样点）。
  - 鼠标拖动时开启事务（支持撤销/重做），联动修改资产参数。

使用场景：需要用可视化方式快速理解/调整正态分布参数，并在蓝图或代码中取样使用。

## 插件二：SuperManager
主要功能
- 右键内容浏览器资产时添加自定义菜单项（通过 Content Browser Extender）：
  - Remove Unused Assets (SuperManager)：删除所选资产中未被引用的资产（先尝试修复 redirectors，再检查引用并删除）。
- UQuickAssetAction（编辑器工具类）暴露的功能（可通过 CallInEditor 或代码调用）：
  - DuplicateAssets(int32 NumberOfDuplicates)：复制选中资产若干份并保存。
  - AddPrefixs()：按类型为选中资产添加命名前缀（BP_, SM_, M_ 等）。
  - RemoveUnusedAssets()：删除选中资产中未被引用的资产（会调用 FixUpRedirectors 以修复重定向器）。

开发/实现要点
- 扩展点通过 FContentBrowserModule::GetAllAssetViewContextMenuExtenders() 注册，使用 FExtender/AddMenuExtension 将菜单插入到 "GetAssetActions" 钩点后。
- 删除逻辑使用 EditorAssetLibrary::FindPackageReferencersForAsset 判断引用并调用 ObjectTools::DeleteAssets 执行删除。
- 修复重定向器使用 AssetRegistry 查询 UObjectRedirector，再由 AssetTools 的 FixupReferencers 处理。

已知问题 & 建议
- 早期实现中对 AssetRegistry 过滤使用了硬编码字符串 "ObjectRedirector" 并直接传裸指针给 FixupReferencers，可能导致过滤不准确或在调用过程中对象被回收引发崩溃。建议/已修复做法：
  - 使用 UObjectRedirector::StaticClass()->GetClassPathName() 填充 FARFilter.ClassPaths。
  - 在调用 FixupReferencers 前通过 FAssetData::GetAsset() 加载并保留 UObject 引用，避免 GC 导致指针失效。
  - 仅在确有 Redirector 列表时才调用 FixupReferencers。
- 更推荐的设计：为 UQuickAssetAction 增加一个公有 API 接口，如 RemoveUnusedAssetsFrom(const TArray<FAssetData>&)，以便直接从扩展回调传入 SelectedAssets，避免修改编辑器的全局选中状态。

调试提示
- 若发生崩溃，查看调用栈定位是否在 AssetTools::FixupReferencer
- 
使用场景：规范资产命名、快速复制测试资源、统一素材前缀等日常批处理。

## 插件三：StaticMeshMaterialSearch (正在开发中)
功能与使用（概述）
- 该插件为编辑器工具，用于在视口中识别鼠标指向的静态网格表面（Material Slot / Material Index），并在内容浏览器或材质浏览器中定位/隔离对应材质。
- 使用方法通常为：
  - 启用插件并重启 Editor。
  - 在视口把鼠标放到目标静态网格上，使用插件提供的命令或工具按钮执行“查找材质”操作（插件具体 UI/命令需查看插件实现的 Editor 模块/工具栏注册）。

开发/扩展建议
- 若希望将该功能脚本化或在工具栏中注册按钮，可在模块 StartupModule 中通过 UToolMenus 或编辑器扩展 API 注册命令。
- 确认插件对多重静态网格、Instanced Mesh 或运行时生成网格的支持边界。

## 插件四：QuickTool
功能与使用（概述）
- 该插件为函数库以及宏库，存储一些个人常用的函数功能。
- 该插件主要用于蓝图中调用，提供便捷的功能接口。
- 目前包含的功能可能涉及数学计算等常用任务。
- 此插件的内容大部分为蓝图实现，便于在蓝图中直接使用和修改，后续会移植到 C++ 实现以提升性能。

使用方法：
  - 在蓝图中添加对 QuickTool 插件的引用。
  - 使用插件提供的函数和宏来实现所需功能。

## 安装与启用
1. 使用与工程匹配的 UE 版本（本项目为 UE 5.3）。
2. 将仓库放置于任意路径，双击 `PluginCreateTest.uproject` 打开工程。
3. 确认 `Edit → Plugins` 中启用：`AssetTutorialPlugin` 与 `SuperManager`（若首次启用需重启编辑器）。

## 使用方法
- 创建正态分布资产：
  - 在内容浏览器空白处右键 → `Miscellaneous`（或相应分类）→ `Normal Distribution`。
  - 双击打开资产，使用“PDF”面板拖拽调整，或在“Details”中直接填值。
  - 在蓝图/代码中可调用 `DrawSample()` 获取采样值，`LogSample()` 在编辑器里可直接输出一次采样到日志。
- 批处理资产：
  - 选中目标资产 → 通过 Editor Utility（或放到关卡蓝图等触发）调用：
    - `DuplicateAssets(NumberOfDuplicates)` 批量复制。
    - `AddPrefixs()` 按类型添加前缀并自动重命名。
    - 在 Content Browser 中选择一个或多个资产（或选中文件夹后右键），右键菜单中查找“Remove Unused Assets (SuperManager)”并点击。
    - 插件内部会将当前选中资产设置为 Editor 的选中状态，然后调用 UQuickAssetAction::RemoveUnusedAssets。


## 构建说明
- 推荐使用 Visual Studio 2022（v144 工具集）与合适的 Windows 10 SDK（如 10.0.19041.0）。
- 若遇到“编译器版本过新”导致的 UBT 报错，可在命令行、`DefaultEngine.ini` 或 `Target.cs` 固定 `CompilerVersion`/`WindowsSdkVersion`（详见工程对话记录与 UBT 源码中的 `-CompilerVersion`/`WindowsTargetSettings`）。

