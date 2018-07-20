#include <iostream>
#include <string>
#include <cstring>

#include "../include/single_line_math.h"
#include "read.cpp"
using namespace std;


int
main(int argc, char *argv[] )
{
	/*
	if (argc < 3)
		cout << "Argument Error!\n"
			"usage: lmd input.lmd output [rtf]" << endl;
	string inputFile = argv[1];
	string outputFile;
	string nullstr;
	if (argc == 4 && strcmp(argv[3], "rtf") == 0)
	{
		outputFile = nullstr + argv[2] + ".rtf";
	}
	else
	{
		outputFile = nullstr + argv[2] + ".html";
	}
	cout << "输入文件为："   << inputFile  << endl;
	cout << "输出文件名为：" << outputFile << endl;
	*/
	SingleLineMath smath;
	smath.setContent("\\frac{a^2 + c^{1+2+3+4+5+6}}{\\sum_{a = 0}^n{a_j}}");

	cout << smath.parse()<< endl;
	cout << getFileContent("./example.html") << endl;
	return 0;
}
