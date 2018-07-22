#include "../include/term.h"

#include <iostream>
using std::cout;


void Title::setContent(string str){
    content = str;
}

string  Title::parse(){
    std::cout << content << std::endl;
    int level = 0;
    //计算头部连续的#个数
    while(content[level++] == '#');

    //标签最大支持到h6
    if (level > 6){
        level = 6;
    }

    string title;

    title = content.substr(level);

    

    std::ostringstream outstr;
    outstr << "<h" << level << ">\n"
            << title << "\n"
            << "</h" << level << ">\n";
    return outstr.str();
}