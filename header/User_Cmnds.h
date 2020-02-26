#ifndef __CMNDS__
#define __CMNDS__

#include "ARGBase.h"

// will do fork, execvp, waitpid
class User_Cmnds : public ARGBase {
   
    protected:
        ARGBase* left = 0;
        ARGBase* right = 0;
        bool op = false; //shows if operator or not for precendce
    
    public:
        User_Cmnds(ARGBase* lef, ARGBase* righ, std::string value) : ARGBase(value), left(left), right(right){}
        User_Cmnds(std::string value): ARGBase(value){}

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


        virtual bool can_execute(){
            return true;
        }

        bool is_operator(){
            return this->op;
        }

};




#endif
