#ifndef __TERM

#define __TERM

#ifndef __STRING
#define __STRING
#include <string>
using std::string;
#endif
#include <sstream>

#ifndef __REGEX
#define __REGEX
#include <regex>
using std::regex;
enum ContinueType{
  CODE,         //代码块
  TABLE,        //表格
  LIST,         //无序列表
  ORDER,        //有序列表
  QUOT,         //引用
  NOTHING       //没有续行
};

//段落级别正则
//无续行元素
static regex title_reg("\\#{1,6} .+?");
static regex split_reg("[\\*\\+\\_\\-]{3,}");
static regex math_reg("\\$\\$.+?\\$\\$");
static regex image_reg("!\\[.*?\\]\\(.+?\\)");

//续行元素,空行结束
static regex list_reg("");
static regex order_reg("");
static regex quot_reg("> .+?");

//空行匹配
static regex space_line_reg("\\s*?");

//续行元素，有结尾标志
static regex code_reg_start("```.*?");
static regex code_reg_end("```");


//\\btab\{c(,c)*?\}\{.*?\}
static regex table_reg_start("\\\\table\\{c(,c)*?\\}\\{.*?\\}");
static regex table_reg_end("\\\\table");



//行内元素正则
static regex bold_reg("[\\*\\+]{2}.+?[\\*\\+]{2}");
static regex italy_reg("[\\*\\-\\+].+?[\\*\\-\\+]");
static regex link_reg("\\[.+?\\]\\(.+?\\)");
static regex cls_reg("\\\\cls\\{.+?\\}\\{.+?\\}");
static regex label_reg("\\\\label\\{.+?\\}");
static regex icode_reg("`.+?`");
static regex imath_reg("\\$.+?\\$");


#endif

//所有标签的父类，声明了公有成员和方法
class Term
{

  protected:
    //保存标签带格式文本
    string content;

  public:
    void setContent(string) {}
    string parse() {}
};

//文档类，每一个lmd文档对应一个类
class Document 
////:public  Term
{
  private:
    string content;
  public:
    string parse();
    void setContent(string);
};

//所有段落级别的抽象父类
class Section ////:public  Term
{
    private:
    string content;

  public:
    string parse() {}
    void setContent(string)  {}
};

//所有内部元素的抽象父类
class Inner ////:public  Term
{  private:
    string content;

  public:
    string parse() {}
    void setContent(string) {}
};

//标题，对应h1-h6标签
class Title ////:public  Section
{
    private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string) ;
    string parse() ;
};
//无序列表
class List ////:public  Section
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};
//有序列表
class Order //:public  Section
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};

//引用

class Quot //:public  Section
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};
//分割线
class Split //:public  Section
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};

// 图片
class Image //:public  Section
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};

// 代码
class Code //:public  Section
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};
// 表格
class Table //:public  Section
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};
// 数学公式
class Math //:public  Section
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};
// 普通文本
class Text //:public  Section
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};

//指定类名
class ClassTerm //:public  Inner
{  private:
    string content;


  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};

class Link //:public  Inner
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};

class Bold //:public  Inner
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};

class Italy //:public  Inner
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};

class InnerMath //:public  Inner
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};

class InnerCode //:public  Inner
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};

class Label //:public  Inner
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};

class PlainText //:public  Inner
{  private:
    string content;

  public:
    static string Grammar;
    static string LaTexGrammar;
    void setContent(string);
    string parse();
};

#endif
