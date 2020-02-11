#ifndef __OR__
#define __OR__

#include "Connector.h"

class Or : public Connector {

	public:
	
	Or(ARGBase* left, ARGBase* right) : Connector(left, right, "||") {}
	Or(): Connector("||"){}
	//void evaluate() {}
};


#endif

