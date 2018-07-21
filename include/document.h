#ifndef __DOCUMENT
#define __DOCUMENT
#include "term.h"


class Document : public Term
{
public:
    virtual string parse();
    virtual void setContent(string);

};


#endif