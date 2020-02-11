#ifndef __AND__
#define __AND__

#include "Connector.h"

class And : public Connector {

	public:
	
	And(ARGBase* left, ARGBase* right) : Connector(left, right, "&&") {}
	And(): Connector("&&"){}
	//void evaluate(){
		
	
};


#endif
