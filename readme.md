> 说明：本项目开发一款在支持Markdown基础语法的的基础上，添加若干类似于Latex的高级功能

> 2018.7.17新增语法：`\cls{clsnames}{content}`，用于对一段内容添加css样式控制。
# 功能说明
主要支持以下几种语法格式：
1. 标题  
	分别对应于HTML的1-6级标题
2. 列表  
	支持有序列表和无序列表，并且列表支持嵌套
3. 引用  
	用于引用外来文字
4. 分割线  
	起到分割的作用
5. 超链接  
	用于指定超链接来跳转到指定位置，超链接嵌套入大多数语法中
6. 图片  
	用于将图片嵌入到文档中
7. 代码  
	使用等宽字体来显示代码，保存内部格式
8. 表格  
	快速的显示出一个表格
9. 跳转  
	用于页面内下锚点，和跳转到指定锚点
10. 流程图  
	用于在文档中显示流程图
11. 控制符号  
	用于支持对内容的一系列控制  
	* 字体大小控制   
		用于控制字体大小
	* 字体颜色控制  
		控制文字前景色
	* 对齐控制  
		控制元素的对齐方式，左中右三种对齐方式
	* 背景色控制  
		控制引用，表格的背景色
	* 边框控制  
		控制表格的边框
	* 文字样式控制  
		控制文字的加粗，斜体，下划线，删除线
	* 其他控制  
		强制断行  
		打印分页

# 语法说明
本段说明语法的基本格式，对于MarkDown语法，添加一台Latex语法，Latex语法则不在添加MarkDown语法。以下MarkDown简称MD
## 标题
用于显示html中的1-6级标题
**MD语法**
> 说明：其基本格式为\#{1,6} .+?
> 此处为了便于处理，取消了标准语法中对#后缀的去除
```
# 一级标题
## 二级标题
...
###### 六级标题
```
--LaTex语法--
> 说明：其基本格式为\\t[1-6]\{.+?\} 
>> 对于所有的非跨行Latex语法，其基本格式都为\cmd{value}
```
\t1{一级标题}
\t2{二级标题}
\t3{三级标题}
...
\t6{六级标题}
```
## 列表
用于显示html中的有序列表和无序列表

### 有序列表
--MD语法--
> 说明：其基本格式为 \d+?\. .+?
> 有序列表中输入的数字编号实际上并不起作用，html会自动设置编号，只需要满足格式即可
```
1. 第一项
1. 第二项
1. 第三项
1. 第四项
```
--Latex语法--
> 说明：其基本格式为：以\bor起头，独占一行，下面的每一行都是一个独立项，以\eor结尾,or取自order的缩写
>> 对于所有的多行Latex语法，都是以\b[cmd]开始，结束于\e[cmd]，取自begin和end的首字母
```
\border
第一项
第二项
第三项
第四项
第五项
\eorder
```


### 无序列表
--MD语法--
> 格式为[\*\-\+]\. .+
> 无序列表中支持`*-+`的混合使用
```
+ 第一项
- 第二项
* 第三项
```
--Latex语法--
> 说明：其基本格式为：以\bli开始，结束于\eli，其中每一行都是一个独立项
```
\bli
第一项
第二项
第三项
\eli
```
## 引用
用于标识引用的文字
--MD语法--
> 说明：其格式为> .+
> 改善MD基础语法，将每行都需要一个>改为第一行需要，后面不需要，使用空行表示引用结束
```
> 这是引用
引用第二行
引用第三行
引用最后一行

```
--Latex语法--
> 说明：开始与\bqu，结束于\equ，其中内部内容依旧支持lmd语法
```
\bqu
引用内容
\equ
```


## 分割线
--MD语法--
> 说明，连续的三个`*-_+`以上转换为分割线
```
---
+++
***
___
```
--Latex语法--
```
\split
\spt
```
## 超链接
--MD语法--
> \[.+?\]\(.+?\)
```
[百度](http://www.baidu.com)
```
--Latex语法--
> 说明：基本格式为\link{alt}{ref}

```
\link{百度}{http://www.baidu.com}
```
## 图片
--MD语法--
> 说明：其基本格式为：![alt](ref)
```
![](图片地址)
```
--Latex语法--
> 说明：其基本格式为\img{alt}{ref}{title}
> 在基本的MD语法上添加了一个title字段，用于在图片的下方显示一个标题
```
\img{}{图片地址}{md示例图片}
```

## 代码
用于在文档中显示代码，分为单行代码和多行代码
--MD语法--
> 说明：单行代码使用``将代码包裹起来，多行代码使用``` ```将代码包裹起来，多行代码可以使用```lang来使得对特定语言进行语法高亮
```
`print("Hello")`

//```cpp
#incldue <iostream>

int
main(){
	std::cout << "Hello World!" << std::endl;
	return 0;
}
//```
```
--Latex语法--
> 单行代码使用\code{value},多行代码使用\bcode开始，结束于\ecode，使用\becode{lang}来指定高亮语言
```
\code{print("123")}

\bcode{cpp}
#incldue <iostream>

int
main(){
	std::cout << "Hello World!" << std::endl;
	return 0;
}
\ecode
```
## 表格
在MD语法的基础上添加Latex版本表格语法
--MD语法--
> 无MD表格语法

--Latex语法--
> 说明：开始于\btab{c,c,c,c}，其中c的个数就是表格的列数，结束于\etab,表中每一行使用|分割
```
\btab{c,c,c}
1|2|3
A|B|C
\etab
```

## 跳转
由于基础MD语法中没有对锚点的支持，只能使用html标签的id属性下锚点，然后使用[]()来进行跳转
--MD语法--
> 不支持
--Latex语法--
> 说明：对于跳转，一共有两个标记，一个是锚点标记，一个是跳转标记。其中跳转标记使用超链接标记即可
> 锚点使用\lab{value}来添加一个id为value的span标签，使用\link{title}{#value}即可跳转到指定的锚点

```
跳转到这里\lab{1-1}


\link{点击跳转}{#1-1}
[点击跳转](#1-1)
```


## 控制符号
控制符号其实是一个大杂烩，所有的不能单独成段的语法都包括在这里面，有以下几种：


### 加粗
--MD语法--
> 说明: 基本格式为 [\*\+\-]{2}.+?[\*\+\-]{2}
```
**bold**
++bold++
--bold--
```
--Latex语法--
> 说明：基本格式为: \b{text}
```
\b{blod string}
```

### 斜体
--MD语法--
> 说明：基本格式为[\*\+\-].+/[\*\+\-]
```
*italy*
+italy+
-italy-
```
--Latex语法--
> 说明：基本格式为\i{text}
```
\i{italy string}
```

### 下划线
MD基础语法并不支持，使用Latex语法进行支持
\ul{text}
```
\ul{UnderLine String}
```

### 删除线
MD基础语法并不支持，使用Latex语法进行支持
\dl{text}
```
\dl{DeleteLine String}
```
<!-- 
### 强制断行
多数情况下使用回车就能断行，MD语法也不支持强制断行，属于Latex语法

--Latex语法--
> 说明：其基本格式为：\\
```
first line\\second line
```

### 字体大小 
> MD基础语法中不支持修改字体大小，这里使用Latex语法进行支持

--Latex语法--
> 说明：其基本格式为\fsz{sizeValue},独立一行，放置于要设置字体大小的文字段后
> 这种情况下设置的格式为一整段，如果想要修改一大段文字中的部分文字的字体大小使用行内的格式\fsz{sizeValue}{text}

```
this is a big pagraph
\fsz{25}

this is a \fsz{25}{big} text
```

### 字体颜色
MD基础语法也不支持设置文字颜色，这里使用Latex语法支持，支持的颜色详情参见`support.md`

--Latex语法--
> 说明：基本格式为：\fcl{colorValue}，独立一行，放置于要设置字体大小的文字段后，影响一整段
> 设置行内的部分字体颜色使用\fcl{colorVlaue}{text}

```
this is a red text
\fcl{red}

this is a \fcl{red}{red text}
```

### 背景色
MD语法也不支持背景色，这里添加背景色设置

--Latex语法--
> 说明：基本格式为\bcl{colorValue}，独立一行，放置于要设置背景色的语法段之后，影响一整段
> 设置行内的部分问题背景色使用\bcl{colorValue}{text}
```
black background text
\bcl{black}


\bcl{black}{black background text}
```

### 对齐方式
MD语法不支持控制元素的对齐方式，这里使用Latex语法进行支持

> 说明，使用\l,\c,\r进行控制靠左居中靠右。独立一行，放置于要控制的元素之后。默认靠左。

```
# 居中标题
\c

\img{alt}{ref}{居右图片}
\r
```


###　表格边框控制
表格的边框控制控制表格元素的边框属性，包括边框样式，边框有无，边框颜色。只能放置于表格定义后`\btab{n,c}`一行

* 边框有无\bd{t} \bd{f}  
* 边框颜色\bdcl{colorValue}  
* 边框样式\bdsty{styleValue}  
	边框样式参见`support.md` -->

## 数学公式
使用`mathjax`进行支持，[github地址](https://github.com/mathjax/mathjax)
使用时在页面加上如下脚本即可
```js
<script type="text/x-mathjax-config">
    MathJax.Hub.Config({tex2jax: {inlineMath: [['$','$'], ['\\(','\\)']]}});
  </script>
  <script type="text/javascript"
    src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
  </script>
```
**其中js脚本可以下载到本地，使用本地支持来避免脚本下载失败的问题**


