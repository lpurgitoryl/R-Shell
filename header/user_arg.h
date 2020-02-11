#ifndef __USERARG__
#define __USERARG__

#include "ARGBase.h"
//will do mkdir ls, -a, echo 
class User_Arg : public ARGBase {
    public:
       User_Arg(ARGBase* left, ARGBase* right, std::string value) : ARGBase(value), first(left), second(right){}
       User_Arg(std::string val): ARGBase(val){}
    protected:
    ARGBase* first;
    ARGBase* second;


};




#endif
