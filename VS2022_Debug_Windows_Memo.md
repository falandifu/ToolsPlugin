# Visual Studio 2022 — 常用调试窗口快捷操作备忘

## 常用调试窗口与打开路径 / 快捷键
- 输出（Output）  
  - 菜单：__View > Output__  
  - 快捷键：__Ctrl+Alt+O__

- 调用堆栈（Call Stack）  
  - 菜单：__Debug > Windows > Call Stack__  
  - 常见快捷键：__Ctrl+Alt+C__（视键位方案可能不同）

- 监视（Watch 1/2/3/4）  
  - 菜单：__Debug > Windows > Watch > Watch 1__（对应 Watch 2/3/4）  
  - 快捷键示例：__Ctrl+Alt+W, 1__（输入序列）

- 局部变量（Locals）  
  - 菜单：__Debug > Windows > Locals__  
  - 快捷键：__Ctrl+Alt+V, L__

- 自动（Autos）  
  - 菜单：__Debug > Windows > Autos__  
  - 快捷键：__Ctrl+Alt+V, A__

- 立即窗口（Immediate）  
  - 菜单：__Debug > Windows > Immediate__  
  - 快捷键：__Ctrl+Alt+I__

- 线程（Threads）  
  - 菜单：__Debug > Windows > Threads__  
  - 常见快捷键：__Ctrl+Alt+H__

- 断点（Breakpoints）  
  - 菜单：__Debug > Windows > Breakpoints__  
  - 快捷键：__Ctrl+Alt+B__

- 异常设置（Exception Settings）  
  - 菜单：__Debug > Windows > Exception Settings__  
  - 快捷键：__Ctrl+Alt+E__

- 诊断工具（Diagnostic Tools）  
  - 菜单：__Debug > Windows > Show Diagnostic Tools__  
  - （通常启动调试时会自动显示）

提示：如果找不到某个窗口，可使用 __View > Other Windows__ 或者在快速启动（__Ctrl+Q__）中搜索窗口名称。

---

## 将常用窗口自动停靠（布局固定 / 自动隐藏 / 保存布局）步骤

1. 打开你需要的调试窗口（参见上方菜单或快捷键）。  
2. 拖动窗口标题栏到编辑器或侧边时，Visual Studio 会显示停靠目标（蓝色提示）。  
   - 将窗口拖到目标区域并释放，窗口会停靠（Dock）到该区域。  
3. 如果想让窗口自动隐藏（只在鼠标靠近时弹出），点击窗口右上角的图钉（Pin）图标使其变为“自动隐藏”。  
4. 要并排停靠多个窗口：拖动窗口到编辑器中心会显示四个象限或边缘停靠目标，选择合适的位置以实现并排或分栏。  
5. 保存自定义布局：使用 __Window > Save Window Layout...__ 输入名称保存当前停靠布局。  
   - 恢复已保存布局：使用 __Window > Apply Window Layout__（或在同一菜单中选择保存的布局）。  
   - 如果想回到默认：使用 __Window > Reset Window Layout__。

小技巧：
- 右键窗口标签可以选择 __Dock__ / __Float__ / __Auto Hide__ 等操作。  
- 将窗口拖到编辑器标签区域可以将其作为标签页并列显示于代码文件之上或之下。

---

## 把备忘导出为 PDF（几种简单方法）

方法 A — 在 Visual Studio 中打印为 PDF：
1. 在 Visual Studio 中打开备忘文件（例如 `Docs/VS2022_Debug_Windows_Memo.md` 或 `.txt`）。  
2. 菜单：__File > Print__。在打印对话中选择打印机为 **Microsoft Print to PDF**，点击打印并存为 PDF 文件。

方法 B — 在编辑器/浏览器中预览并打印为 PDF：
1. 使用支持 Markdown 渲染的编辑器（例如 VS Code）打开 `*.md`，使用预览功能渲染。  
2. 在渲染视图中使用 __Print__（浏览器或编辑器的打印）并选择 **保存为 PDF**。

方法 C — 使用 Pandoc（命令行，需安装 Pandoc）：
- 命令示例：