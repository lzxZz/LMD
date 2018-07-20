/*
��д�ļ�����
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

//���ļ����뵽string��
string readFileIntoString(const char *filename)
{
    ifstream ifile(filename);
    //���ļ����뵽ostringstream����buf��
    ostringstream buf;
    char ch;
    while (buf && ifile.get(ch))
        buf.put(ch);
    //������������buf�������ַ���
    return buf.str();
}