#ifndef __COLON__
#define __COLON__

#include "Connector.h"

class Colon : public Connector {

	public:
	
	Colon(ARGBase* left, ARGBase* right) : Connector(left, right, ";") {}
	Colon(): Connector(";"){}
	//void evaluate(){}
	bool can_execute(){
	// if(left->can_execute(first,second)){
    //    	        if(right->can_execute(first,second)){
	// 	return true;
	// 	}
	// }
	// return false;
	return true; //colon executes each side no matter what
	}
};


#endif


