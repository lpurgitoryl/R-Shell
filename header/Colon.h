#ifndef Colon.h
#define Colon.h


class Colon : public Connector {

	public:
	Colon(Basemenu* left, Basemneu* right) : Connector (), first(left), second(right) {}


	private:
	Basemenu* first;
	Basemenu* right;

};

#endif //Colon.h


