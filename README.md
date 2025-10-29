# ToolsPlugin
自用 UE 工具插件集合（UE5.1）。

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
提供常用的资产批处理能力，提升工作流效率：
- `UQuickAssetAction`（Editor Utility，`CallInEditor`）：
  - `DuplicateAssets(NumberOfDuplicates)`：批量复制当前选中资产，每个生成后自动保存并统计成功数，完成后显示通知。
  - `AddPrefixs()`：根据资产类型自动添加统一前缀，覆盖范围示例：
    - Blueprint → `BP_`，StaticMesh → `SM_`，Material → `M_`，MaterialInstance → `MI_`
    - MaterialFunction → `MF_`，ParticleSystem → `PS_`
    - SoundCue → `SC_`，SoundWave → `SW_`
    - Texture/Texture2D → `T_`，UserWidget → `WBP_`
    - SkeletalMeshComponent → `SK_`，NiagaraSystem → `NS_`，NiagaraEmitter → `NE_`
  - 特殊规则：若为 `UMaterialInstanceConstant`，会移除名称中的 `M_` 前缀与 `_inst` 后缀后再加前缀，避免冗余。
- `DebugHeader.h`：提供简单的调试与 UI 提示封装（屏幕打印、日志输出、对话框、通知等）。

使用场景：规范资产命名、快速复制测试资源、统一素材前缀等日常批处理。

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

## 构建说明
- 推荐使用 Visual Studio 2022（v144 工具集）与合适的 Windows 10 SDK（如 10.0.19041.0）。
- 若遇到“编译器版本过新”导致的 UBT 报错，可在命令行、`DefaultEngine.ini` 或 `Target.cs` 固定 `CompilerVersion`/`WindowsSdkVersion`（详见工程对话记录与 UBT 源码中的 `-CompilerVersion`/`WindowsTargetSettings`）。

## 许可
- 仅用于个人学习与内部工具示例。
