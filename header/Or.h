#ifndef Or.h
#define Or.h

#include "Connector.h"

class Or : public Connector {

	public:
	
	Or(Basemenu* left, Basemenu* right) : Connector(), first(left), second(right) {}



	private:
	Basemenu* first;
	Basemenu* second;

};


#endif

