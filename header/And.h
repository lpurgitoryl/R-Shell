#ifndef AND.H
#define AND.H


#include "Connector.h"

class And : public Connector {
	public:

	And() {};
	And(Basemenu* left, Basemenu* right) : Basemenu(),first(left),second(right) {}

	

	private:
	Basemenu* first;
	Basemenu* second;

};
#endif //ADD.H
