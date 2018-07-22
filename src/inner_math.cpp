#include "../include/term.h"

string InnerMath::Grammar = "\$.+?\$";
void InnerMath::setContent(string str)
{
    content = str;
}

string InnerMath::parse() {}