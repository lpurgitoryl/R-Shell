#ifndef __OR__
#define __OR__

#include "Connector.h"

class Or : public Connector {

	public:
	
	Or(ARGBase* left, ARGBase* right) : Connector(left, right, "||") {}
	Or(): Connector("||"){}
	//void evaluate() {}
	bool can_execute(int first,int second){
	if (left->can_execute(first,second) && !right->can_execute(first,second)){ //checks if left works and right ddoesn't
	return true;
	}
	else if (!right->can_execute(first,second)){ //checks if left doesn't work and right does
		if(left->can_execute(first,second)){
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

