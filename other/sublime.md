#sublime使用方法

##安装package control
在网络搜索
##使用github
通过使用GitGutter工具，使用 [github地址](https://github.com/jisaacks/GitGutter)

##安装Markdown
+ 安装[MarkdownEditing](https://github.com/SublimeText-Markdown/MarkdownEditing)
默认将txt识别为Markdown文件，排除方法：【右下角】【Open all with current extension as】【?】未解决
+ 安装[sublimetext-markdown-preview](https://github.com/revolunet/sublimetext-markdown-preview)
**添加快捷键ctrl+m**
【preference】【key binding - user】{ "keys": ["alt+m"], "command": "markdown_preview", "args": {"target": "browser", "parser":"markdown"} }
**解决md文件配色和布局问题**
在markdown editing GFM default中添加如下内容：
"color_scheme": "Packages/MarkdownEditing/MarkdownEditor-Dark.tmTheme",
"draw_centered": false,
+ [Markdown语法](https://github.com/younghz/Markdown)

##开发环境
Go语言
	下载go语言编译工具：go1.7rc6.windows-386.msi，安装
	在sublime中Install Package->GoSublime

##配置皮肤
Theme - Soda和Theme - Flatland

1. 使用package ctl安装：Theme - Soda或Theme - Flatland，
	或者在github下载：[地址](https://github.com/buymeasoda/soda-theme https://github.com/thinkpixellab/)
2. 修改Sublime Text -> Preferences -> Settings - User，在其中加入如下内容
		soda：
			{
			    "theme": "Soda Light.sublime-theme"
			}
			或者：Soda Dark.sublime-theme
			具体参考github地址
	Flatland：
		{
		  "theme": "Flatland Dark.sublime-theme",
		  "color_scheme": "Packages/Theme - Flatland/Flatland Dark.tmTheme"
		}
