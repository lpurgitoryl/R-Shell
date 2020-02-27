#ifndef __ARGBASE__
#define __ARGBASE__


#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stack>
#include <queue>
#include <algorithm>

//PARENT CLASS TO CONNECTOR AND USER COMMANDS
class ARGBase{

    protected:

   // std::string ARGname;
    std::string ARGValue;// c-tostring ()
   // char* commands [100]; MAKE FUNCTION TO CONVERT TO CHAR
  //ARGBase* left = 0;
  //ARGBase* right = 0; 
    public:

    // ARGBase(std::string name, std::string value){
    //     ARGname = name;
    //     ARGValue = value;
    // }

    ARGBase( std::string value){
        //ARGname = name;
        ARGValue = value;
       // std::cout << "\n" << ARGValue << " THIS IS constructor  FROM BASE" <<  std::endl;
        
    }

    //  std::string getARGname(){
    //     return ARGname;

    // }
     std::string getARGValue(){
       // std::cout  << "\n this is value called from base class and gts string\n " << ARGValue; 
        return ARGValue;
    }

    virtual bool can_execute() = 0;

    virtual void set_left(ARGBase* lef) = 0;
    virtual void set_right(ARGBase* righ) = 0;
    virtual ARGBase* get_left() = 0;
    virtual ARGBase* get_right() = 0;
    virtual bool is_operator() = 0;

    //  virtual void evaluate() = 0;


    // void set_ARGName(std::string symbol){
    //     ARGname = symbol;
    // }

    // void set_left(ARGBase* lef){
    //    left = lef;
    // }

    // void set_left(ARGBase* righ){
    //    right = righ;
    // }
};

#endif 
