#include "../include/term.h"
#include "../include/read.h"

string Table::parse()
{
    std::ostringstream os;
    std::vector<string> lines;
    SplitString(content, lines, "\n");


    string cls = lines[0].substr(7);
    cls = cls.substr(0,cls.size() -1);
    
    std::vector<string> classes;
    SplitString(cls,classes,",");

    os << "<table cellspacing=\"0\" class=\"" ;
    for (auto c:classes){
        os << c << " ";
    }
    os << "\">" << std::endl;

    for (vector<int>::size_type i = 1; i<lines.size() ; i++){
        std::vector<string> items;
        SplitString(lines[i],items,"|");
        os << "<tr>" << std::endl;
        for (auto item:items){
            Text tmptext;
            tmptext.setContent(item);
            os << "<td>" << tmptext.parse() << "</td>" << std::endl;
        }
        os << "</tr>" << std::endl;
    }

    os << "</table>" << std::endl;
    return os.str();
}