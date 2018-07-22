#include "../include/term.h"
#include "../include/read.h"
#include <regex>

using std::regex;

void Document::setContent(string str)
{
    content = str;
}

string Document::parse()
{
    vector<string> lines;
    SplitString(content, lines, "\n");

   
    //开始处理每一行数据
    regex treg(Title::Grammar);
    int index = 1;
    std::ostringstream outstr;
    for (auto line : lines)
    {

        if (regex_match(line, treg))
        {
            std::cout << "conv:" << index++ << "\n";

            Title tmptitle;
            tmptitle.setContent(line);
            outstr << tmptitle.parse();
        }
    
    }

    return outstr.str();
}
