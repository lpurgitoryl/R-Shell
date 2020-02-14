#ifndef _PARSER_
#define _PARSER_

#include "ARGBase.h"
#include "Colon.h"
#include "Or.h"
#include "And.h"
#include "User_Cmnds.h"
#include "Connector.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

class Parser{
    private:
        //std::string cmdInput;
        istringstream cmdInput;
       // char* connectValues [";", "&&", "||"] ;


    public:
        Parser(string input): cmdInput(input){ }

        vector<ARGBase*> parse();
        void find_connectors(vector <ARGBase*>& tokens);
        ARGBase* split_up();
        void tokenize(istringstream& cmdInput ,  vector <ARGBase*>& tokens);
        void create_tree_vector(vector <ARGBase*>& tokens);
        char** create_array(vector <ARGBase*>& tokens);

};



#endif
