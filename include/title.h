#ifndef __TITLE
#define __TITLE
#include "document.h"
using std::string;

class Title : public Document
{
  public:
    static string Grammar;
    static string LaTexGrammar;
    virtual void setContent(string);
    virtual string parse();
};
#endif