#ifndef __INPUTREDIRECTION__
#define __INPUTREDIRECTION__

#include "Connector.h"

class InputRedirection : public Connector{

    InputRedirection(ARGBase* left, ARGBase* right) : Connector(left, right, "<"){}
    InputRedirection() : Connector("<"){}
    bool can_execute(){
        return true; 
    }
};


#endif