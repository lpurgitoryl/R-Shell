#ifndef __CMNDS__
#define __CMNDS__

#include "ARGBase.h"

// will do fork, execvp, waitpid
class User_Cmnds : public ARGBase {
    public:
    
        User_Cmnds(ARGBase* left, ARGBase* right, std::string value) : ARGBase(value), first(left), second(right){}
    protected:
    ARGBase* first;
    ARGBase* second;
};




#endif
