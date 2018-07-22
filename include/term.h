#ifndef __TERM
//#include "term.h"
#define __TERM

#ifndef __STRING
#define __STRING
#include <string>
using std::string;
#endif

//所有标签的父类，声明了公有成员和方法
class Term
{

  protected:
    //保存标签带格式文本
    string content;

  public:
    virtual void setContent(string) = 0;
    virtual string parse() = 0;
};

//文档类，每一个lmd文档对应一个类
class Document : public Term
{
  public:
    virtual string parse();
    virtual void setContent(string);
};

//所有段落级别的抽象父类
class Section : public Term
{
  public:
    virtual string parse() = 0;
    virtual void setContent(string) = 0;
};

//所有内部元素的抽象父类
class Inner : public Term
{
  public:
    virtual string parse() = 0;
    virtual void setContent(string) = 0;
};

//标题，对应h1-h6标签
class Title : public Section
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};
//无序列表
class List : public Section
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};
//有序列表
class Order : public Section
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};

//引用

class Quot : public Section
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};
//分割线
class Split : public Section
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};

// 图片
class Image : public Section
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};

// 代码
class CodeBlock : public Section
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};
// 表格
class Table : public Section
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};
// 数学公式
class Math : public Section
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};
// 普通文本
class Text : public Section
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};

//指定类名
class ClassTerm : public Inner
{

  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};

class Link : public Inner
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};

class Bold : public Inner
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};

class Italy : public Inner
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};

class InnerMath : public Inner
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};

class InnerCode : public Inner
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};

class Label : public Inner
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};

class PlainText : public Inner
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};

#endif