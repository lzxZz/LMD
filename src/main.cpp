#include <iostream>
#include <string>
#include <cstring>
#include <regex>
#include "../include/read.h"
#include "../include/term.h"
#include <stdlib.h>

using namespace std;

//用法，lmd inputfilename
//		lmd inptufilename outputfilename cssfile1,cssfile2.....
void printHelp(){
	cout << "lmd is a extention of markdown,grammer reference readme.md file\n\n\n" << endl;
	cout << "Usage: lmd [-c/-o <outfile>] [-css <value1,value2...>] [-char <caharset>] [-h] input" << endl;
	cout << "	-c		this is argument means is the result of parsing will print to terminal" << endl;
	cout << "		if you input this argument,the -o argument is invalid\n" << endl;
	cout << "	-o		this arugment will change the output filename" << endl;
	cout << "		the default output filename is input filename with \".html\" extension\n" << endl;
	cout << "	-css	this argument can help you to specify the css file that you want to use in you htmlfile" << endl;
	cout << "		the css file will use the <link> label\n" << endl;
	cout << "	-char	this argument is used to specify the charset used in the file. \n" << endl;
	cout << "	-h		to print help info to you screen" << endl;
	cout << "		if you input this argument ,all of the other argument is invalid\n" << endl;
	cout << "	input	this file is the filename of you want to parse to html\n\n\n" << endl;

}


int main(int argc, char *argv[])
{
	//是否有-h参数
	bool isPrintHelp = false;
	//是否有-c参数
	bool isOutToTerminal = false;
	//输入文件名
	string input = "";
	//输出文件名
	string output = "";
	//css列表，逗号隔开
	string csses = "";
	//字符集，默认u8
	string charset = "utf-8";

	//使用数组标识参数是否读取过，以取出输入文件。
	int *use =  (int*)malloc(sizeof(int) * argc);
	//初始化标识数组，0表示未使用，1表示使用
	for (int i = 0; i < argc; i++){
		use[i] = 0;
	}
	//第一个参数为程序名
	use[0] = 1;

	//循环遍历参数列表
	for (int i = 0; i < argc;i++)
	{
		string arg = argv[i];
		if (arg == "-h")
		{
			printHelp();
			return 0;
		}
		if (arg == "-c")
		{
			isOutToTerminal = true;
			use[i] = 1;
		}
		if (arg == "-o")
		{	
			use[i] = 1;
			output = argv[++i];
			use[i] = 1;
		}
		if (arg == "-css")
		{
			use[i] = 1;
			csses = argv[++i];
			use[i] = 1;
		}
		if (arg == "-char")
		{
			use[i] = 1;
			charset = argv[++i];
			use[i] = 1;
		}
		if (arg == "")
		{
			use[i]  = 1;
		}
	}
	//取出输入文件名
	for (int i = 0; i < argc; i++){
		if (use[i] != 1){
			input = argv[i];
		}
	}

	//如果没有指定输出文件名，使用输入文件名改后缀为html作为输出文件名
	if (output == ""){
		output =  input.substr(0,input.find_last_of("."));
		output += ".html";
	}


	
#if 0
	cout << "input		" << input << endl;
	cout << "output		" << output << endl;

	cout << "isterm		" << isOutToTerminal << endl;

	cout << "charset		" << charset << endl;
	cout << "csses		" << csses << endl;
	
#endif
	//没有输入文件名，打印帮助信息，退出程序
	if (input == ""){
		printHelp();
		return 0;
	}

	std::ostringstream os;

	//Doc转换器
	Document doc;
	//Term *doc = new Document();

	//设置转换器要转换的内容
	doc.setContent(readFileIntoString(input.c_str()));
	

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
	SplitString(csses,cssvec,",");
	for (string css:cssvec)
	{
		os << "<link rel=\"stylesheet\" type=\"text/css\" href=\"" << css << "\"></link>" << endl;
	}

	//输出html剩下内容
	os << "</head>\n"
	   << "<body>\n"
	   << doc.parse()				//输出转换出来的结果
	   << "</body>\n"
	   << "</html>\n"
	   << endl;

	
	//根据-c参数的有无，选择输出到终端还是文件
	if (isOutToTerminal){
		cout << os.str() << endl;
	}else{
		ofstream writer;
		writer.open(output.c_str());
		
		writer << os.str() << endl ;
	
		writer.close();
	}

	return 0;

}
