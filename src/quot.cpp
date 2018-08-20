#include "../include/term.h"
#include "../include/read.h"
#include <vector>


string Quot::parse(){
    std::ostringstream os;

    Document doc;
    std::ostringstream docstr;
    std::vector<string> lines;
    SplitString(content,lines,"\n");
    for(auto line:lines){
        if (line[0] == '>'){
            if (line[1] == ' '){
                docstr << line.substr(2) << std::endl;
            }else{
                docstr << line.substr(1) << std::endl;
            }

        }else{
            docstr << line << std::endl;
        }

    }
    docstr << "" << std::endl;

  //  std::cout << "---------------\n" << docstr.str() << "---------------\n" << std::endl;
    doc.setContent(docstr.str());

    os << "<blockquote>"
        << doc.parse()
        << "</blockquote>" << std::endl;

    return os.str();
}