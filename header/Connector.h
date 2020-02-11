#ifndef __CONNECTOR__
#define __CONNECTOR__

#include <Basemenu.h>

class Connector: public Basemenu {
  
    public:
      //  bool execute(){
        //    return prev && post ;
       // };
    Connector(){};
    Connector(Basemenu* left, Basemenu* right) : Basemenu(), first(left), second(right){}
	
    private:
	Basemenu* first;
	Basemenu* second;
};


#endif
