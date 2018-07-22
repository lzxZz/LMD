#include "../include/term.h"

string Italy::Grammar = "\[\*\-\+\].+?\[\*\-\+\]";

void Italy::setContent(string str) { content = str; }
string Italy::parse() {}