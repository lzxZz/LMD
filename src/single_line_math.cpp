#include "../include/single_line_math.h"

void  SingleLineMath::setContent(string content)
{
    this->content = content;
}

string SingleLineMath::parse(){
    return "<span>" + content + "</span>";
}