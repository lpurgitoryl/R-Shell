#include "../header/Parser.h"
void Parser::infixtopostfix(vector<ARGBase*>& tokens){
    //shunting yard
    //(echo a || echo b)
    stack<ARGBase*>signs;
    queue<ARGBase*>hold;
    ARGBase* temp;
    for (int i = 0; i < tokens.size(); i++){
        if (tokens.at(i)->getARGValue() != "||" && tokens.at(i)->getARGValue() != "&&" && tokens.at(i)->getARGValue() != ";" && tokens.at(i)->getARGValue() != "(" && tokens.at(i)->getARGValue() != ")" ){
            //echo,a
            hold.push(tokens.at(i)); 
            // implement edge case here
            if (i+1 != tokens.size()){
            i++;
            hold.push(tokens.at(i));
           // cout << "here";
            }
        }
        else if (tokens.at(i)->getARGValue() == "&&" || tokens.at(i)->getARGValue() == "||" || tokens.at(i)->getARGValue() == ";" || tokens.at(i)->getARGValue() == "(" || tokens.at(i)->getARGValue() == ")"){
            if (tokens.at(i)->getARGValue() == ")"){ //finding )
                while(signs.top()->getARGValue() != "("){ //popping until (
                    temp = signs.top();
                    signs.pop();
                    hold.push(temp);
                    if (signs.top()->getARGValue() == "("){
                        signs.pop(); //removing ( from the stack
                    }
                }
            }
         //cout << "here" << endl; //not reaching here
        //implement removing parenthesis
            signs.push(tokens.at(i));
        }
    }
    //ls -a || echo a && echo b
    //after the vector and empty and there are still stuff in the stack
    if (!signs.empty()){
        while(!signs.empty()){
            temp = signs.top();
            hold.push(temp);
            signs.pop();
           // cout << "jer" ;
        }
    }
    //printing the value of queue to see

    while(!hold.empty()){
        //cout << "here";

        temp = hold.front();
        cout << temp->getARGValue();
        hold.pop();
        //cout << "here";
    }
}
void Parser::create_tree_vector(vector <ARGBase*>& tokens){
// string command = "";
// ARGBase* root;
// ARGBase* temp;
//      //ARGBase* tree; //new tree
//      //root = tree;
//       for (int i = 0; i < tokens.size(); i++) {
//           if(tokens.at(i)->getARGValue() != "&&" || tokens.at(i)->getARGValue() != "||" || tokens.at(i)->getARGValue() != ";"){//checks for any connectors;
//               if (command == "")
//               command += tokens.at(i)->getARGValue();
//               else{
//                   command = command + " " + tokens.at(i)->getARGValue();
//               }
//           }
//           else if (tokens.at(i)->getARGValue() == "&&" || tokens.at(i)->getARGValue() == "||" || tokens.at(i)->getARGValue() == ";")
//                  if (root == nullptr || root->get_left() == nullptr){
//                      root = tokens.at(i);
//                      User_Cmnds* com = new User_Cmnds(command);
//                      root->set_left(com);    
//                 }
//             }
//         }
    }

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
       if (uptoSpace !="$" && uptoSpace != "&&" && uptoSpace != "||" && uptoSpace != ";" && uptoSpace != "" && uptoSpace != "\n" && uptoSpace != "(" && uptoSpace != ")"){
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
       else if (uptoSpace == "("){
           tokens.push_back(new LParen());
       }
       else if (uptoSpace == ")"){
           tokens.push_back(new RParen());
       }

   }while (cmdInput);

    return;
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


