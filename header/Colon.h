#ifndef __COLON__
#define __COLON__

#include "Connector.h"

class Colon : public Connector {

	public:
	
	Colon(ARGBase* left, ARGBase* right) : Connector(left, right, ";") {}
	Colon(): Connector(";"){}
	//void evaluate(){}
	bool can_execute(){
	
		return 0; //colon executes each side no matter what
		
	}
};


#endif


