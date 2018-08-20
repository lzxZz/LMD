#include "../include/term.h"
#include "../include/read.h"



string List::parse()
{
    std::ostringstream os;

    os << "<ul>" << std::endl;
    std::vector<string> lines;
    SplitString(content, lines, "\n");
    regex reg("[\\*\\+] .+?");

    regex tab_reg("\\t");

    Document doc;
    doc.setContent("");
    string docstr = "";
    for (auto line : lines)
    {
        //std::cout << line << std::endl;
        if (regex_match(line, reg))
        {
            docstr += "\n\n";
            doc.setContent(docstr);
            os << doc.parse() << std::endl;

            //用于支持列表项的行内语法
            Document tmpdoc;
            tmpdoc.setContent(line.substr(2));
            os << "<li>" << tmpdoc.parse() << "</li>" << std::endl;
            docstr = "";
        }
        else
        {
            //std::cout << line;
            string tmpline = line;
            //将tab替换为四个空格
            regex_replace(tmpline, tab_reg, "    ");
            if (tmpline.compare(0, 4, "    ") == 0)
            {
                docstr += tmpline.substr(4) + "\n";
            }
            else
            {
                docstr += tmpline + "\n";
            }
        }
    }
    docstr += "\n\n";
    doc.setContent(docstr);
    os << doc.parse() << std::endl;
    os << "</ul>" << std::endl;
    return os.str();
}