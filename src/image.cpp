#include "../include/term.h"

string Image::Grammar = "!\[\.+?]\(\.+?)";
string Image::LaTexGrammar = "\\\\img\{.*?\}\{.+?\}\{.+?\}";

void Image::setContent(string str){
    content = str;
}

string Image::parse(){
    
}