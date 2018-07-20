/*
*所有非段落元素的父类
*
*/
#include <string>
using std::string;

class InnerTerm{
private:
    string content; //内部文本

public:
    void setContent(string);
    string parsing();
}