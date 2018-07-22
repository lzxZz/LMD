#include "../include/term.h"

string List::LaTexGrammar = "";
string List::Grammar = "\[\-\+\*\]\. .+?";

void List::setContent(string str){
    content  = str;
}

string List::parse(){}