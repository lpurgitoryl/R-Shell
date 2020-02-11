#ifndef __COLON__
#define __COLON__

#include "Connector.h"

class Colon : public Connector {

	public:
	
	Colon(ARGBase* left, ARGBase* right) : Connector(left, right, ";") {}
	Colon(): Connector(";"){}
	//void evaluate(){}
};


#endif


