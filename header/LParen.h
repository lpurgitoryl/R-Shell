#ifndef __LPAREN__
#define __LPAREN__


#include "Connector.h"

class LParen : public Connector {

    public:
    LParen(ARGBase* left, ARGBase* right) : Connector(left, right, "(") {}
	LParen(): Connector("("){}
    bool can_execute(){}

};


#endif