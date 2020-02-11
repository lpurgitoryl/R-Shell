#ifndef __ARGBASE__
#define __ARGBASE__


#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//PARENT CLASS TO CONNECTOR AND USER COMMANDS
class ARGBase{

    protected:
   // std::string ARGname;
    std::string ARGValue;
    // ARGBase* left = 0;
    // ARGBase* right = 0;
    
    public:

    // ARGBase(std::string name, std::string value){
    //     ARGname = name;
    //     ARGValue = value;
    // }

    ARGBase( std::string value){
        //ARGname = name;
        ARGValue = value;
    }

    //  std::string getARGname(){
    //     return ARGname;

    // }
     std::string getARGValue(){
        return ARGValue;
        
    }

    virtual bool can_execute() = 0;
    virtual void evaluate() = 0;


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
