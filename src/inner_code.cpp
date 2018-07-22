#include "../include/term.h"

string InnerCode::Grammar = "`.+*`";

void InnerCode::setContent(string str)
{
    content = str;
}

string InnerCode::parse() {}