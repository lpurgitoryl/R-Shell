#ifndef __CMNDS__
#define __CMNDS__

#include "ARGBase.h"

// will do fork, execvp, waitpid
class User_Cmnds : public ARGBase {
    public:
            virtual bool can_execute(int left, int right){
                return true;
            }
            void set_left(ARGBase* lef){
            left = lef;
            }

            void set_right(ARGBase* righ){
            right = righ;
            }
             ARGBase* get_right(){
            return this->right;
            }
            ARGBase* get_left(){
            return this->left;
            }
            
        User_Cmnds(ARGBase* lef, ARGBase* righ, std::string value) : ARGBase(value), left(left), right(right){}
        User_Cmnds(std::string value): ARGBase(value){}
    protected:
    ARGBase* left = 0;
    ARGBase* right = 0;
};




#endif
