#ifndef __ARGBase__
#define __ARGBase__

#include <iostream>
#include <string>

class ARGBase{

    private:
    std::string ARGname;
    std::string ARGValue;

    public:

    ARGBase(std::string name, std::string value){
        ARGname = name;
        ARGValue = value;
    }

     std::string getARGname(){
        return ARGname;

    }
     std::string getARGValue(){
        return ARGValue;
        
    }

};

#endif 
