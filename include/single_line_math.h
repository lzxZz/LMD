/*
*行内数学公式，套一个span，原样输出即可
*/

#include <string>
using std::string;

class SingleLineMath{
private:
    string content;
public:
    void setContent(string);
    string parse();
};
