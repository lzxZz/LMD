/*
*行内数学公式，套一个span，原样输出即可
*/

#ifndef __STRING
#define __STRING
#include <string>
using std::string;
#endif

class SingleLineMath{
private:
    string content;
public:
    void setContent(string);
    string parse();
};