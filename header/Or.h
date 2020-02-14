#ifndef __OR__
#define __OR__

#include "Connector.h"

class Or : public Connector {

	public:
	
	Or(ARGBase* left, ARGBase* right) : Connector(left, right, "||") {}
	Or(): Connector("||"){}
	//void evaluate() {}
	bool can_execute(){
	if (left->can_execute() && !right->can_execute()){ //checks if left works and right ddoesn't
	return true;
	}
	else if (!right->can_execute()){ //checks if left doesn't work and right does
		if(left->can_execute()){
		return true;
		}
	}
	else{
	return false;//checks if both are false
	}
	return true;
	}
};


#endif

