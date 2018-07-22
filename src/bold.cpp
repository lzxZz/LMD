#include "../include/term.h"

string Bold::Grammar = "\[\*\-\+\]{2}.+?\[\*\-\+\]{2}";

void Bold::setContent(string str)
{
    content = str;
}
string Bold::parse()
{
}