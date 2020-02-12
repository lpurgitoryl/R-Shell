#ifndef __COLON__
#define __COLON__

#include "Connector.h"

class Colon : public Connector {

	public:
	
	Colon(ARGBase* left, ARGBase* right) : Connector(left, right, ";") {}
	Colon(): Connector(";"){}
	//void evaluate(){}
	bool can_execute(int first, int second){
	if(left->can_execute(first,second)){
       	        if(right->can_execute(first,second)){
		return true;
		}
	}
	return false;
	}
};


#endif


