/*
读写文件操作
*/

#include "../include/read.h"

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

vector<string> readFileLines(const char *pathname)
{
    vector<string> lines;
    ifstream ifile(pathname);
    string buf;
    while (getline(ifile, buf))
    {
        lines.push_back(buf);
    }
    return lines;
}
void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
 
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}