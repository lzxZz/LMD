#include "../include/term.h"
string Link::Grammar = "\[.+?\]\(.+?\)";
string Link::LaTexGrammar = "\\\\link\{.+?\}\{.+?\}"

void Link::setContent(string str){
    content = str;
}

string Link::parse(){
    
}