#ifndef __ONEOUTPUTREDIRECTION__
#define __ONEOUTPUTREDIRECTION__

#include "Connector.h"

class Oneoutputredirection : public Connector{

    public:

    Oneoutputredirection(ARGBase* left, ARGBase* right) : 
    Connector(left, right, ">"){}

    Oneoutputredirection() : Connector(">"){}
    
    bool can_execute(){
        return true; 
    }
};


#endif