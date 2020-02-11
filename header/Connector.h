#ifndef __CONNECTOR__
#define __CONNECTOR__

#include "ARGBase.h"

//PARENT CLASS TO CONNECTOR CLASES OR AND COLON

class Connector: public ARGBase {
    protected:
    ARGBase* first;
    ARGBase* second;

    public:
      //  bool execute(){
        //    return prev && post ;
       // };

    Connector(ARGBase* left, ARGBase* right, std::string value) : ARGBase(value), first(left), second(right){}
    Connector(std::string value): ARGBase(value){}
    //virtual void evaluate();
	
    
};


#endif
