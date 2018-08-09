
# 已知缺陷：
> 单行代码格式` `contnet` `其中也会支持格式的嵌套\\


LMD解释器V1.0
    目前发布的windows版本，windows10下编译通过。**输入文件必须要是GB2312编码**
    2018.8.9更新，将输入文件格式修改为utf8，输出的html指定编码为utf8。



# 用法说明
程序名为`lmd.exe`，调用格式为：`lmd.exe input.lmd [out.html] [cssfiles ...]`
* 只有`input`参数时，转换结果将会输出到控制台。
* 输入`input`和`output`参数时，转换结果将会输出到`output`中。
* 第三个开始及之后的参数全部都会被转换为`<srcipt>`标签，用于传入自定义的`css`文件。


# `lmd`语法
> 将所有的语法(标签)分成两类，一类称之为段落级语法，能够独自称为一个段落，另一类称之为行内语法，不能单独成段，基本上用`<span>`标签包裹。

**段落语法**

\table{}
标签名称|语法格式|示例|备注
标题|`1-6个#+space+内容`|# 一级标题|继承自md
有序列表|`数字+.+space+列表项`|1. 有序列表|继承自md
无序列表|`'*','+'+space+列表项`|* 列表项(+ 列表项)|继承自md
分割线|`三个以上重复的'*','-','+'`| ***(---)(+++++)|继承自md
数学公式|`$$LATEX语法$$`|$$frac{1}{2}$$|由mathjax支持
图片|`![alt](src)`|![示例图片](网络图片地址)|继承自md
引用|`>+space+content`|> 引用内容|继承自md
代码块|代码缺陷无法展示|代码缺陷|继承自md
表格|见此项lmd文件|见此项lmd文件|见此项lmd文件
\table

```
\table{}
标签名称|语法格式|示例|备注
标题|1-6个#+space+内容|# 一级标题|继承自md
有序列表|数字+.+space+列表项|1. 有序列表|继承自md
无序列表|'*','+'+space+列表项|* 列表项(+ 列表项)|继承自md
分割线|三个以上重复的'*','-','+'| ***(---)(+++++)|继承自md
数学公式|$$LATEX语法$$|$$frac{1}{2}$$|由mathjax支持
图片|![alt](src)|![示例图片](网络图片地址)|继承自md
引用|>+space+content|> 引用内容|继承自md
代码块|```lang\n+codelines+\n+```|```cpp\nint sum(int,int);|继承自md
表格|见此项lmd文件|见此项lmd文件|见此项lmd文件
\table
```

**行内语法**\\

\cls{red}{以下的语法允许嵌套使用，并且支持在除去代码块中的所有语法}

\table{}
标签名称|示例
加粗|**content**
斜体|*content*
超链接|[content](link)
指定类|cls{classnames}{}
锚点|\label{id}
行内代码|`code`
行内数学公式|$a = b + c$
\table

```
\table{}
标签名称|示例
加粗|**content**
斜体|*content*
超链接|[content](link)
指定类|cls{classnames}{}
锚点|\label{id}
行内代码|`code`
行内数学公式|$a = b + c$
\table
```

