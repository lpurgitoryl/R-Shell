#ifndef __RParen__
#define __RParen__

#include "Connector.h"


class RParen : public Connector {

    public:
    RParen(ARGBase* left, ARGBase* right) : Connector(left, right, ")") {}
	RParen(): Connector(")"){}
    bool can_execute(){}
};


#endif


