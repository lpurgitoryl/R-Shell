#ifndef __CONNECTOR__
#define __CONNECTOR__

#include <ARGBase.h>

class Connector: public ARGBase {
    private:
       bool prev = true;
       bool post = true;
    public:
        bool can_execute(){
            return prev && post ;
        };


};


#endif