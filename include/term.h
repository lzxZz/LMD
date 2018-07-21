#ifndef __TERM
//#include "term.h"
#define __TERM


#ifndef __STRING
#define __STRING
#include <string>
using std::string;
#endif

//所有标签的父类，声明了公有成员和方法
class Term{

protected:
    //保存标签无格式文本(例如，加粗标签为**加粗**，就只保存“加粗”)
    string content;

public:
    virtual void setContent(string) = 0;
    virtual string parse() = 0;

};

#endif