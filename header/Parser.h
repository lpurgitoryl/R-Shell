#ifndef _PARSER_
#define _PARSER_

#include "ARGBase.h"
#include "user_arg.h"
#include "Colon.h"
#include "Or.h"
#include "And.h"
#include "User_Cmnds.h"
#include "Connector.h"

#include <iostream>
#include <vector>
#include <sstream>



using namespace std;

class Parser{
    private:
       // std::string cmdInput;
       istringstream cmdInput;
        ARGBase* tokenize( std::string vals,  vector <ARGBase*>& tokens);
        

    public:
        Parser( std::string input){
           cmdInput >> input;
        }

        vector<ARGBase*> parse();

};



#endif
