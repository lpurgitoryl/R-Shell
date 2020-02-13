#ifndef __CONNECTOR__
#define __CONNECTOR__

#include "ARGBase.h"

//PARENT CLASS TO CONNECTOR CLASES OR AND COLON

class Connector: public ARGBase {
    protected:
    ARGBase* left = 0;
    ARGBase* right = 0;

    public:
      //  bool execute(){
        //    return prev && post ;
       // };

    Connector(ARGBase* left, ARGBase* right, std::string value) : ARGBase(value), left(left), right(right){}
    Connector(std::string value): ARGBase(value){}
    //virtual void evaluate();
	
    
};


#endif
