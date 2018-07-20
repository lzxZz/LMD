/*
读写文件操作
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::fstream;
using std::string;
using std::stringstream;
using std::ifstream;
using std::ostringstream;

//从文件读入到string里
string readFileIntoString(const char *filename)
{
    ifstream ifile(filename);
    //将文件读入到ostringstream对象buf中
    ostringstream buf;
    char ch;
    while (buf && ifile.get(ch))
        buf.put(ch);
    //返回与流对象buf关联的字符串
    return buf.str();
}