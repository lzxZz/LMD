/*
读写文件操作
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "code_conv.cpp"


using std::string;
using std::fstream;
using std::stringstream;
string getFileContent(const char *file){
    fstream fs;
    stringstream ss;
    fs.open(file);
    
    string buf;

    std::cout << "start read" << std::endl;

    if (!fs){
        std::cout << "open file error" << std::endl;
        std::cout << file << std::endl;
    }

    while (fs){
        fs >> buf;
        ss << buf;
        std:: cout << "读取内容" << buf  << std::endl;
    }

    fs.close();
    
    return ss.str();
}
