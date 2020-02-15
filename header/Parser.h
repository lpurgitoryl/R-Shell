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
       // ARGBase* root = nullptr;

    public:
        Parser(string input): cmdInput(input){ }

        vector<ARGBase*> parse();
        //void find_connectors(vector <ARGBase*>& tokens);
        int find_comment_index(vector <ARGBase*>& tokens);//returns -1 if none found
        void remove_comment(vector <ARGBase*>& tokens, int index);//removes
       // ARGBase* split_up();
        int num_colons(vector <ARGBase*>& tokens);
        void tokenize(istringstream& cmdInput ,  vector <ARGBase*>& tokens);
        //void create_tree_vector(vector <ARGBase*>& tokens);
        char** create_array(vector <ARGBase*>& tokens);

};



#endif
