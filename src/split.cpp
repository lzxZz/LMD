#include "../include/term.h"

string Split::Grammar = "[\*\-\+]{3,}";

void Split::setContent(string str){ content = str;}

string Split::parse(){return "\n<hr />\n";}