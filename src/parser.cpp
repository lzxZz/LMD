#include "../include/parser.h"
#include "../include/read.h"
#include <sstream>

using std::ostringstream;

 string Parser::Parse(string css,string charset,string content){
    ostringstream os;
    Document doc;
    doc.setContent(content);

    //输出html头
	os << "<!DOCTYPE html>\n"
	   << "<html>\n"
	   << "<head>\n"
	   << "<meta charset=\"" << charset << "\">\n"				//输出字符集
	   << "<script type=\"text/x-mathjax-config\">\n"
	   << "MathJax.Hub.Config({tex2jax: {inlineMath: [['$','$'], ['\\(','\\)']]}});\n"
	   << "</script>\n"
	   << "<script type=\"text/javascript\" src=\"http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML\"></script>\n";

	//分开逗号分隔的css文件，用link标签嵌入
	vector<string> cssvec;
	SplitString(css,cssvec,",");
	for (string css:cssvec)
	{
		os << "<link rel=\"stylesheet\" type=\"text/css\" href=\"" << css << "\"></link>" << std::endl;
	}

	//输出html剩下内容
	os << "</head>\n"
	   << "<body>\n"
	   << doc.parse()				//输出转换出来的结果
	   << "</body>\n"
	   << "</html>\n"
	   << std::endl;

    return os.str();
 }