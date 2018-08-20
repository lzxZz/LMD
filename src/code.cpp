#include "../include/term.h"


string Code::parse(){
    string lang = content.substr(3,content.find('\n')-3);

    string codes = content.substr(content.find('\n'));
    
    std::ostringstream os;

    os << "<pre>\n<code lang=\"" 
        << lang << "\">" 
        << codes 
        << "</code>\n</pre>";
    return os.str();
}