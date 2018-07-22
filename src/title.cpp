#include "../include/term.h"

string Title::Grammar = "\\#{1,6} .+?";
string Title::LaTexGrammar = "\\\\t[1-6] .+?";

void Title::setContent(string str){
    content = str;
}

string  Title::parse(){
    return "Title";
}