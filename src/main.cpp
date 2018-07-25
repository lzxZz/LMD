#include <iostream>
#include <string>
#include <cstring>
#include <regex>
#include "../include/read.h"
#include "../include/term.h"

using namespace std;

//用法，lmd inputfilename
//		lmd inptufilename outputfilename cssfile1,cssfile2.....

int main(int argc, char *argv[])
{
	string input;
	if (argc < 2)
	{
		cout << "usage: lmd inputfile [outfile] [cssfile1 ...] " << endl;
		return -1;
	}
	input = argv[1];
	string outfile;
	if (argc >= 3)
	{
		outfile = argv[2];
	}

	std::ostringstream os;

	Document doc;

	//std::cout << readFileIntoString("./test.md") << endl;
	doc.setContent(readFileIntoString(input.c_str()));
	

	os << "<!DOCTYPE html>\n"
	   << "<html>\n"
	   << "<head>\n"
	   << "<script type=\"text/x-mathjax-config\">\n"
	   << "MathJax.Hub.Config({tex2jax: {inlineMath: [['$','$'], ['\\(','\\)']]}});\n"
	   << "</script>\n"
	   << "<script type=\"text/javascript\" src=\"http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML\"></script>\n";

	for (int i = 3; i < argc; i++)
	{
		os << "<link rel=\"stylesheet\" type=\"text/css\" href=\"" << argv[i] << "\"></link>" << endl;
	}

	os << "</head>\n"
	   << "<body>\n"
	   << doc.parse()
	   << "</body>\n"
	   << "</html>\n"
	   << endl;

	if (argc == 2){
		cout << os.str() << endl;
	}else{
		ofstream writer;
		writer.open(outfile.c_str());
		
			writer << os.str() << endl ;
	
		writer.close();
	}


	return 0;
}
