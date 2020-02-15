#ifndef __AND__
#define __AND__

#include "Connector.h"

class And : public Connector {

	public:
	
	And(ARGBase* left, ARGBase* right) : Connector(left, right, "&&") {}
	And(): Connector("&&"){}
	//void evaluate(){
	bool can_execute(){
	if (left->can_execute()){ //first checks if left can execute
		if(right->can_execute()){ //thens checks right
			return 0;
		}
	}
	return 1; //return false because left or right is not true
	}	
		
	
};


#endif
