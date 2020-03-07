#ifndef __TWOOUTPUTREDIRECTION__
#define __TWOOUTPUTREDIRECTION__

#include "Connector.h"

class Twooutputredirection : public Connector{

    Twooutputredirection(ARGBase* left, ARGBase* right) : Connector(left, right, ">>"){}
    Twooutputredirection() : Connector(">>"){}
    bool can_execute(){
        return true; 
    }
};


#endif