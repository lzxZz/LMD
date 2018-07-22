#include "../include/term.h"
#include "../include/read.h"
void Document::setContent(string str){
    content = str;
}

string Document::parse(){
    vector<string> lines;
    SplitString(content,lines,"\n");

    vector<Section> sections;
    //开始处理每一行数据
    for (auto line:lines){


    }

    return "document";
}