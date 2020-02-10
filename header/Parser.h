#ifndef _PARESER_
#define _PARESER_

#include <ARGBase.h>
#include <iostream>
#include <vector>



using namespace std;

class Parser{
    private:
        int argInputs;
        char* argValues;
        ARGBase* tokenize(char* Values);
        

    public:
        Parser(int argc, char* argv ){
            argInputs = argc;
            argValues = argv;
        }

        vector<ARGBase*> parse();

};



#endif