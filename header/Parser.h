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
        //std::string cmdInput;
        istringstream cmdInput;
       // char* connectValues [";", "&&", "||"] ;


    public:
        Parser(string input): cmdInput(input){ }
      //  Parser(){}

        vector<ARGBase*> parse();
        void find_connectors();
        void is_connectors(vector <ARGBase*>& tokens);
      //  void remove_newlineprompt(); // removes $ keeps first space
        ARGBase* split_up();
        void tokenize(istringstream& cmdInput ,  vector <ARGBase*>& tokens);
       // void prompt();
        void create_tree_vector(vector <ARGBase*>& tokens);

};



#endif
