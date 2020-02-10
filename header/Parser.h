#ifndef _PARESER_
#define _PARESER_

#include <ARGBase.h>
#include <iostream>
#include <vector>



using namespace std;

class Parser{
    private:
        std::string cmdInput;
        ARGBase* tokenize(char* Values);
        

    public:
        Parser( std::string input){
            cmdInput =input;
        }

        vector<ARGBase*> parse();

};



#endif