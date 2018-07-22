#include "../include/term.h"

string Label::LaTexGrammar = "\\\\lb{.+?}";

void Label::setContent(string str){
    content = str;
}
string Label::parse(){}