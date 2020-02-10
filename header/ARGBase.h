#ifndef __ARGBase__
#define __ARGBase__

#include <iostream>
#include <string>

class ARGBase{

    private:
    std::string ARGname;
    std::string ARGValue;
   // int status = 0;
   // ARGBase* left = 0;
    //ARGBase* right = 0;
    public:

    ARGBase(std::string name, std::string value){
        ARGname = name;
        ARGValue = value;
    }

    ARGBase( std::string value){
        //ARGname = name;
        ARGValue = value;
    }

     std::string getARGname(){
        return ARGname;

    }
     std::string getARGValue(){
        return ARGValue;
        
    }

    void set_ARGName(std::string symbol){
        ARGname = symbol;
    }

    //void set_left(ARGBase* lef){
      //  left = lef;
    //}

    //void set_left(ARGBase* righ){
      //  right = righ;
    //}
};

#endif 
