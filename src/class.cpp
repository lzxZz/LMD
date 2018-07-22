#include "../include/term.h"

string ClassTerm::LaTexGrammar = "\\\\cls\{.+?\}\{.+?\}";
string ClassTerm::Grammar = "";
void ClassTerm::setContent(string str){
    content  = str;
}
string ClassTerm::parse(){

}