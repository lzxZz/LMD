#include "../include/term.h"
#include "../include/read.h"

void Order::setContent(string str){content = str;}

string Order::parse(){
     std::ostringstream os;

    os << "<ol>" << std::endl;
    std::vector<string> lines;
    SplitString(content, lines, "\n");
    
    regex reg("\\d+\\. .+?");

    regex tab_reg("\\t");
    regex index_reg("\\d+\\.");

    Document doc;
    doc.setContent("");
    string docstr ="";
    for (auto line : lines)
    {
        //std::cout << line << std::endl;
        if (regex_match(line, reg))
        {
            docstr += "\n\n";
            doc.setContent(docstr);
            os << doc.parse() << std::endl;
            Document tmpdoc;
            tmpdoc.setContent(regex_replace(line,index_reg,"",std::regex_constants::format_first_only));
            os << "<li>" << tmpdoc.parse() << "</li>" << std::endl;
            docstr = "";
        }else{
            //std::cout << line;
            string tmpline = line;
            //将tab替换为四个空格
            regex_replace(tmpline,tab_reg,"    ");
             if (tmpline.compare(0,4,"    ") == 0){
            docstr += tmpline.substr(4) + "\n";
            }else{
                docstr += tmpline + "\n";
            }
        }
    }
    docstr += "\n\n";
    doc.setContent(docstr);
    os << doc.parse() << std::endl;
    os << "</ol>" << std::endl;
    return os.str();
}