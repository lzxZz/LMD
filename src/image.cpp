#include "../include/term.h"

#include <iostream>
#include <sstream>
using std::ostream;




string Image::parse(){
   string alt = content.substr(2,content.find(']')-2);
   string src = content.substr(content.find('('));
   src = src.substr(1,src.size()-2);
   
   std::ostringstream os;
   os << "<img src=\"" 
        << src 
        << "\" alt=\"" 
        << alt 
        << "\" />";

   return os.str();
}