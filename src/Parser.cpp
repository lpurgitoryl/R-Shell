#include "../header/Parser.h"

//  void Parser::create_tree_vector(vector <ARGBase*>& tokens){
   
//  }

int Parser::find_comment_index(vector <ARGBase*>& tokens){
    int hash = -1;
     for(int i = 0; i < tokens.size(); i++){
        if( tokens.at(i)->getARGValue() == "#" || tokens.at(i)->getARGValue().at(0) == '#'  ){
            hash = i;// index of comment location
            return hash;
        }
     }
     return hash;//retunrs -1 if no comment is found
}

 void Parser::remove_comment(vector <ARGBase*>& tokens, int indexHash){
     
    int index = tokens.size() - indexHash;
     while(index >= 1){
        // cout << "Token to be removed at this index: " << index<< " " << tokens.at(index)->getARGValue() << endl;
         tokens.pop_back();
         index--;
     }
     return;
 }
//for every space seprate the "words" into user cmds toekns and push to 
//the vector
void Parser::tokenize(istringstream& cmdInput  , vector <ARGBase*>& tokens ){
//creates token vector from input and then tokenizes to either connector or user cmnd
 do{
       string uptoSpace;
       cmdInput >> uptoSpace;
       if (uptoSpace !="$" && uptoSpace != "&&" && uptoSpace != "||" && uptoSpace != ";" && uptoSpace != "" && uptoSpace != "\n"){
       tokens.push_back(new User_Cmnds(uptoSpace));
       cout << "value here is not a connector ->" << tokens.back()->getARGValue() << "<-" << endl;
       }
       else if(uptoSpace == "&&"){
           tokens.push_back(new And());
       }
       else if(uptoSpace == "||"){
           tokens.push_back(new Or());
       }
       else if(uptoSpace == ";"){
           tokens.push_back(new Colon());
       }

   }while (cmdInput);

    return;
}

 void Parser::infix_to_postfix(vector <ARGBase*>& tokens){//doesn not take () yet
     stack<ARGBase*> non_operators; //aka output
     stack<ARGBase*> operators; // 

    for(int i = 0; i < tokens.size(); i++){
        //no white space is in the token vecotr
        //checking if operator is present
        //presedence for operators is the same except ; separates an and ()
        if(tokens.at(i)->getARGValue().at(0) == '('){//checks for ()
            operators.push(new Parenth("("));
             
        }
        if(tokens.at(i)->is_operator() != true){ //meaning some command
            non_operators.push(tokens.at(i));
            cout << "this token was pushed to non_op queue:->" << tokens.at(i)->getARGValue() << "<-" << endl;
        }


    }


 }

char** Parser::create_array(vector <ARGBase*>& tokens){
    char ** cmnds = NULL;

    cmnds = (char**) malloc((tokens.size()) * sizeof(char*)); //allocates "lenghth" of 2d array

   // cout << tokens.size() << " this is token size \n";
    //cout << "before for loop" << endl;
    for (int i = 0; i < tokens.size() ; i++){
        cmnds[i] = (char*) malloc( tokens.at(i)->getARGValue().size() * sizeof(char)); //allocates space for string @ index
        char * vals = const_cast<char*>(  tokens.at(i)->getARGValue().c_str());
        strcpy(cmnds[i], vals);
      //  cout << cmnds[i] << endl;
    } 
    cmnds[tokens.size()] = NULL; //creates end with null
    
    return cmnds;

}

vector<ARGBase*> Parser::parse(){
    vector <ARGBase*> tokens;
    // 
    tokenize(cmdInput, tokens) ;
    for(int i = 0; i < tokens.size(); i++){//tester for correct values in tokens
            cout << "this is token number: " << i << " and the value is " << endl;
            cout << "value here ->" << tokens.at(i)->getARGValue() << "<-" << endl;
        
        }

    cout << tokens.size() << "<- this is size" << endl;
    int indexComment = find_comment_index(tokens);
    cout << "this is the comment location (-1 if NA):" << indexComment << endl; 
    if(indexComment != -1){
      remove_comment(tokens, indexComment);
    }

    cout << tokens.size() << "<- this is size" << endl;
    // for(int i = 0; i < tokens.size(); i++){//tester for correct values in tokens
    //         cout << "this is token number: " << i << " and the value is " << endl;
    //         cout << "value here ->" << tokens.at(i)->getARGValue() << "<-" << endl;
        
    //     }
    
return tokens;

}


