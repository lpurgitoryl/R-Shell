#ifndef __CONNECTOR__
#define __CONNECTOR__

#include "ARGBase.h"

//PARENT CLASS TO CONNECTOR CLASES OR AND COLON

class Connector: public ARGBase {
    protected:
    ARGBase* left = 0;
    ARGBase* right = 0;
    bool op = true; //shows if operator or not for precendce 
    public:
      //  bool execute(){
        //    return prev && post ;
       // };

    Connector(ARGBase* left, ARGBase* right, std::string value) : ARGBase(value), left(left), right(right){}
    Connector(std::string value): ARGBase(value){}
   

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
    //virtual void evaluate();
   bool is_operator(){
         return this->op;
   }
	
    
};


#endif
