#include "../include/term.h"

using std::ostringstream;

string PlainText::parse(){
    ostringstream os;

    os << "<span class=\"plain_text\">\n"
        << content
        << "\n</span>\n";

    return os.str();
}

void PlainText::setContent(string str){
    content  = str;
}