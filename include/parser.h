/* 文档转换类，讲一个lmd语法的文档转化为html
*
*
*创建于2018-08-26    write by lzx
*/
#include "term.h"
#include <string>
using std::string;
class Parser{

public:
    string Parse(string css,string ch,string content);
};