#ifndef __USERARG__
#define __USERARG__

#include "ARGBase.h"

class User_Arg : public ARGBase {
    public:
       User_Arg(ARGBase* left, ARGBase* right, std::string value) : ARGBase(value), first(left), second(right){}
       
    protected:
    ARGBase* first;
    ARGBase* second;


}




#endif