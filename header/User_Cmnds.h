#ifndef __CMNDS__
#define __CMNDS__

#include "ARGBase.h"

// will do fork, execvp, waitpid
class User_Cmnds : public ARGBase {
    public:
    virtual void execute();
    
};




#endif
