#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int
main(int argc, char *argv[] )
{
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
	return 0;



}
