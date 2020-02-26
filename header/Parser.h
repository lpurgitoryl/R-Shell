#ifndef _PARSER_
#define _PARSER_

#include "ARGBase.h"
#include "Colon.h"
#include "Or.h"
#include "And.h"
#include "User_Cmnds.h"
#include "Connector.h"
#include "Parenthesis.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;

class Parser{
    private:
        //std::string cmdInput;
        istringstream cmdInput;
       // char* connectValues [";", "&&", "||"] ;
        ARGBase* root = nullptr;

    public:
        Parser(string input): cmdInput(input){ }

        vector<ARGBase*> parse();
        //void find_connectors(vector <ARGBase*>& tokens);
        int find_comment_index(vector <ARGBase*>& tokens);//returns -1 if none found
      //  int find_quote_index(); //searches only userCmnd and gets rid of all quotes
       // void remove_quotes(); // uses find quotes to get rid of them
        //
        void remove_comment(vector <ARGBase*>& tokens, int index);//removes
       // ARGBase* split_up();
        //int num_colons(vector <ARGBase*>& tokens);
        void tokenize_grouping(istringstream& cmdInput ,  vector <ARGBase*>& tokens); //separates/groups cmnds from connectors EX. echo hello || echo hello is stored in a vector as ["echo hello" "||" "echo hello"]
        void tokenize_each_input(istringstream& cmdInput ,  vector <ARGBase*>& tokens);//separates each input as its seprate object EX. echo hello || echo hello is stored in a vector as ["echo" "hello" "||" "echo" "hello"]
        vector<ARGBase*> infix_to_postfix(vector <ARGBase*>& tokens);
        void create_tree_vector(vector <ARGBase*>& tokens);
        char** create_array(vector <ARGBase*>& tokens);

};



#endif
