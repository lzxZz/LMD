#include "../include/term.h"
#include "../include/read.h"
#include <iostream>

using std::smatch;
using namespace std::regex_constants;
using std::cout;
void Text::setContent(string str)
{
    content = str;
}

// Text类支持的元素有：
//     加粗
//     斜体
//     超链接
//     锚点
//     单行代码
//     单行数学公式
//     指定类名

regex newline_reg("\\\\\\\\");

string Text::parse()
{
    smatch match;
    while (regex_search(content, match, newline_reg))
    {
        

        content = regex_replace(content, newline_reg, "<br />", match_flag_type::format_first_only);
    }

    while (regex_search(content, match, bold_reg))
    {
        string text = match.str().substr(2);
        text = text.substr(0, text.size() - 2);

        content = regex_replace(content, bold_reg, "<b>" + text + "</b>", match_flag_type::format_first_only);
    }

    while (regex_search(content, match, italy_reg))
    {
        string text = match.str().substr(1);
        text = text.substr(0, text.size() - 1);

        content = regex_replace(content, italy_reg, "<i>" + text + "</i>", match_flag_type::format_first_only);
    }

    while (regex_search(content, match, link_reg))
    {
        string text = match.str();
        string label = text.substr(1, text.find(']'));
        string ref = text.substr(text.find('(') + 1);
        ref = ref.substr(0, ref.size() - 1);
        label = label.substr(0, label.size() - 1);

        content = regex_replace(content, link_reg, "<a href=\"" + ref + "\" >" + label + "</a>", match_flag_type::format_first_only);

        //cout << ref << "\n" << label ;
    }

    while (regex_search(content, match, label_reg))
    {
        string text = match.str();
        string id = text.substr(7);
        id = id.substr(0, id.size() - 1);

        ostringstream os;
        os << "<span id=\"" << id << "\"></span>" << std::endl;

        content = regex_replace(content, label_reg, os.str(), match_flag_type::format_first_only);
    }

    while (regex_search(content, match, icode_reg))
    {
        string icode = match.str().substr(1);
        icode = icode.substr(0, icode.size() - 1);
        ostringstream os;
        os << "<code class=\"icode\">" << icode << "</code>" << std::endl;
        content = regex_replace(content, icode_reg, os.str(), match_flag_type::format_first_only);
    }

    while (regex_search(content, match, imath_reg))
    {
        string imath = match.str().substr(1);
        imath = imath.substr(0, imath.size() - 1);
        ostringstream os;
        //由于数学公式只需要原样输出即可，效果由mathjax实现，为了防止死循环，这里将$替换为&dollar;
        os << "<span class=\"imath\">" << "&dollar;" << imath << "&dollar;" << "</span>" << std::endl;
        content = regex_replace(content, imath_reg, os.str(), match_flag_type::format_first_only);
    }

    while (regex_search(content, match, cls_reg))
    {

        string text = match.str();
        vector<string> calsses;
        string classtext = text.substr(5, text.find('}') - 5);
        SplitString(classtext, calsses, ",");

        ostringstream os;

        os << "<span class=\"";
        for (auto cls : calsses)
        {

            os << cls << " ";
        }
        os << "\">" << std::endl;
        string value = text.substr(text.find('}') + 2);
        value = value.substr(0, value.size() - 1);
        os << value << "</span>" << std::endl;
        content = regex_replace(content, cls_reg, os.str(), match_flag_type::format_first_only);
    }
    regex dollar_reg("&dollar;");
    content = regex_replace(content,dollar_reg,"$");

    return content;
}