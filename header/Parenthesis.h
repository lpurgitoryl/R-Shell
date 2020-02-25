#ifndef __Parenthesis__
#define __Parenthesis__

#include "Connector.h"

class Parenth : public Connector {

	public:
	
	Parenth(ARGBase* left, ARGBase* right, std::string value) : Connector(left, right, value) {}
	Parenth(std::string value): Connector(value){}
	//void evaluate(){}
	bool can_execute(){
	
		return 0; //colon executes each side no matter what
		
	}
    
};


#endif