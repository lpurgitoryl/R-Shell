#ifndef __AND__
#define __AND__

#include "Connector.h"

class And : public Connector {

	public:
	
	And(ARGBase* left, ARGBase* right) : Connector(left, right, "&&") {}
	And(): Connector("&&"){}
	//void evaluate(){
	bool can_execute(int first, int second){
	if (left->can_execute(first,second)){ //first checks if left can execute
		if(right->can_execute(first,second)){ //thens checks right
			return true;
		}
	}
	return false; //return false because left or right is not true
	}	
		
	
};


#endif
