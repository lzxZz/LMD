#include <iostream>
#include <string>
#include <vector>

#ifndef STR_USING
#define STR_USING
using std::string;
#endif

#ifndef VEC_USING
#define VEC_USING
using std::vector;
#endif


//storage the label inner text
string content;

//return the html code
string pasre();

//set the label inner text
void setContent();

//return the lable inner text
string getContent();
