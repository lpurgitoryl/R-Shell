#ifndef __PIPE__
#define __PIPE__

#include "Connector.h"

class Pipe : public Connector {

	public:
	
	Pipe(ARGBase* left, ARGBase* right) :
	Connector(left, right, "|") {}
	
	Pipe(): Connector("|"){}
	//void evaluate(){
	bool can_execute(){
		
	return 0;
	}	
		
	
};


#endif