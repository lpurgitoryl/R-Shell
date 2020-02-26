#include "../header/Parser.h"
vector <ARGBase*> Parser::infix_to_postfix(vector<ARGBase*>& tokens){
    //shunting yard
    //(echo a && echo b) || (echo c && echo d)
    //(echo d && echo c) || (echo b && echo a)
    //how to deal with semicolons in terms of executor,
    //use another vector that passes in first to reverse the vector that checks the parenthesis if ) then ( if ( then )
    // ||&&echo a echo b && echo c echo d
    // (echo a && echo b) || echo c
    // echo c || (echo b && echo a)
    // || && echo a echo b echo c
    vector<ARGBase*>vals;
    vector<ARGBase*>mirror;
    stack<ARGBase*>signs;
    queue<ARGBase*>hold;
    ARGBase* temp;
    //mirror the vector
    for (int i = tokens.size()-1; i >= 0; i--){
        if (tokens.at(i)->getARGValue() == ")"){
            mirror.push_back(new Parenth("("));
        }
        else if (tokens.at(i)->getARGValue() == "("){
            mirror.push_back(new Parenth(")"));
        }
        else{
            mirror.push_back(tokens.at(i));
        }
    }
    for (int i = 0 ; i < mirror.size(); i++){
        cout << mirror.at(i)->getARGValue();
    }
    //shunting yard
    // ((echo a || echo b) && echo c)
    // (echo c && (echo b || echo a))
    for (int i = 0; i < mirror.size(); i++){
        if (mirror.at(i)->getARGValue() != "||" && mirror.at(i)->getARGValue() != "&&" && mirror.at(i)->getARGValue() != ";" && mirror.at(i)->getARGValue() != "(" && mirror.at(i)->getARGValue() != ")" ){
            //echo,a
            hold.push(mirror.at(i)); 
            // implement edge case here
           // if (i+1 != tokens.size()){
            //i++;
            //hold.push(tokens.at(i));
           // cout << "here";
            //}
        }
        else if (mirror.at(i)->getARGValue() == "&&" || mirror.at(i)->getARGValue() == "||" || mirror.at(i)->getARGValue() == ";" || mirror.at(i)->getARGValue() == "(" || mirror.at(i)->getARGValue() == ")"){

            if (mirror.at(i)->getARGValue() == ")"){ //finding )
                while(signs.top()->getARGValue() != "("){ //popping until ( //logic here wrong
                    temp = signs.top();
                    signs.pop();
                    hold.push(temp);
                }
                if (signs.top()->getARGValue() == "("){
                        signs.pop(); //removing ( from the stack
                    }
            }
         //cout << "here" << endl; //not reaching here
        //implement removing parenthesis
            else{
            signs.push(mirror.at(i));
            }
        }
    }
    //ls -a || echo a && echo b
    //after the vector and empty and there are still stuff in the stack
    if (!signs.empty()){
        while(!signs.empty()){
            // if (signs.top()->getARGValue() == "(" || signs.top()->getARGValue() == ")"){
            //     cout << "error";
            // }
            //else{
            temp = signs.top();
            hold.push(temp);
            signs.pop();
           // }
           // cout << "jer" ;
        }
    }
    //printing the value of queue to see

    // while(!hold.empty()){
    //     //cout << "here";

    //     temp = hold.front();
    //     cout << temp->getARGValue();
    //     hold.pop();
    //     //cout << "here";
    // }
    // storing values into a vector
    while(!hold.empty()){
        temp = hold.front();
        vals.push_back(temp);
        hold.pop();
    }
    //printing the  vector
    // (echo a || echo b) && echo c
    // echo c && (echo b || echo a)
    cout << endl;
    cout << "here" << endl;
    for (int i = 0; i <vals.size(); i++){
        cout << vals.at(i)->getARGValue();
    }
    cout << endl;

    for (int i = 0; i <vals.size(); i++){
        reverse(vals.begin(), vals.end());
    }
    for (int i = 0; i <vals.size(); i++){
        cout << vals.at(i)->getARGValue();
    }
    //reversing a vector
    return vals;
}

void Parser::create_tree_vector(vector <ARGBase*>& tokens){
    //(echo a && echo b) || (echo c && echo d)
    //(echo d && echo c) || (echo b && echo a)
    //|| && echo a echo b && echo c echo d
    //((echo a || echo b) && echo c)
    // &&|| echo a echo b echo c
    //(echo a || echo b) && (echo c || echo d) && (echo e || echo f)
    //&& && || echo a echo b || echo c echo d || echo e echo f
    ARGBase* root;
    ARGBase* temp;
    ARGBase* prev;
    for (int i = 0; i < tokens.size(); i++){
        root = tokens.at(0); //first value will be an index
        if (tokens.at(i)->getARGValue() == "&&" || tokens.at(i)->getARGValue() == "||"){ //checking for the second index to be a connector or not
            if(root->get_left() == NULL){
                root->set_left(tokens.at(i));
                temp = root->get_left(); //setting our temp to left in order to make tree
            }
            //moving to left if next command is an operand and moving temp along left side of tree
            else if (temp->get_left() == NULL){ 
                temp->set_left(tokens.at(i));
                prev = temp;
                temp = temp->get_left();
            }
            else if (root->get_right() == NULL){
                root->set_right(tokens.at(i));
                temp = root->get_right(); // setting temp to right
            }
        }
        else if (tokens.at(i)->getARGValue() != "||" && tokens.at(i)->getARGValue() != "&&"){
            if (temp->get_left() == NULL){
                temp->set_left(tokens.at(i));
            }
            else if (temp->get_right() == NULL){
                temp->set_right(tokens.at(i));
                temp = prev;
            }
        }
    }






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
void Parser::tokenize_each_input(istringstream& cmdInput  , vector <ARGBase*>& tokens ){
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

   }while (cmdInput);

    return;
}

void Parser::tokenize_grouping(istringstream& cmdInput ,  vector <ARGBase*>& tokens){

    cout << "-------------------------------------------------\n This is grouping tokens\n\n" << endl;
    string groupedValue = "";
    bool found_connector = false; //flag in case of no connector

    do{
        string uptoSpace;
        cmdInput >> uptoSpace;

       if (uptoSpace !="$" && uptoSpace != "&&" && uptoSpace != "||" && uptoSpace != ";" && uptoSpace != "" && uptoSpace != "\n"){
       //tokens.push_back(new User_Cmnds(uptoSpace));
       cout << "\nvalue here is not a connector ->" << uptoSpace << "<-" << endl;

       //check for parenthesis
            if(uptoSpace.at(0) == '('){ //checks right ( at start of string
                    cout << "\n-------------parantheis check (---------------\nthis is the value of the input before->" << uptoSpace << "<-" << endl;

                    string noParenthesis = uptoSpace.substr(1, string::npos ); //copys untill end of string with out the (
                    cout << "\n this is the string with no  Parenthestis ->" << noParenthesis << "<-\n";

                    uptoSpace = noParenthesis; //now equal to string with out (
                    groupedValue += uptoSpace + " ";

                    cout << "\n this is the grouped value " << groupedValue << endl;

                    tokens.push_back(new Parenth("("));
                    cout << "\n-------------parantheis check (---------------\nthis is the value of the input AFTER->" << uptoSpace << "<-" << endl;
                    cout << "\n-------------parantheis check ( end---------------\n";
                    cout << "this is the current string ->" << groupedValue << "<-" << endl;
            }
            else if(uptoSpace.at(uptoSpace.size() - 1 ) == ')'){//checks last index
                cout << "\n-------------parantheis check )---------------\nthis is the value of the input before->" << uptoSpace << "<-" << endl;
                uptoSpace.pop_back(); //delets last char which is the )...now equal to string with out )
                groupedValue += uptoSpace;

                  cout << "\n this is the grouped value " << groupedValue << endl;

                tokens.push_back(new User_Cmnds(groupedValue));
                cout << "this is the current string ->" << groupedValue << "<-" << endl;
                groupedValue = "";
                tokens.push_back(new Parenth(")") );
            // groupedValue = "";//reset for next input after )
                cout << "\n-------------parantheis check )---------------\nthis is the value of the input AFTER->" << uptoSpace << "<-" << endl;
                cout << "-------------parantheis check ) end---------------\n";
                found_connector = true;
            }
            else{
                groupedValue += uptoSpace + " ";
                  cout << "\n this is the grouped value " << groupedValue << endl;
            }

       
       } 
    // here groupValue could be empty 
       else if(uptoSpace == "&&"){
                cout << "\n this is the grouped value before pop->" << groupedValue << "<-" << endl;
                
                if(!groupedValue.empty() ){
                groupedValue.pop_back(); // gets rid of space at end

                cout << "\n this is the grouped value after pop->" << groupedValue << "<-" <<endl;
           
                tokens.push_back(new User_Cmnds(groupedValue));
                }
           tokens.push_back(new And());
           cout << endl << tokens.back()->getARGValue() << endl;
           groupedValue = ""; //resets string for use after cmnd
           found_connector = true;
       }
       else if(uptoSpace == "||"){
            cout << "\n this is the grouped value before pop->" << groupedValue << "<-" << endl;
            if(!groupedValue.empty() ){
                groupedValue.pop_back(); // gets rid of space at end
                cout << "\n this is the grouped value after pop->" << groupedValue << "<-" << endl;

                tokens.push_back(new User_Cmnds(groupedValue));
            }
           tokens.push_back(new Or());
           cout << endl << tokens.back()->getARGValue() << endl;
           groupedValue = ""; //resets string for use after cmnd
           found_connector = true;
       }
       else if(uptoSpace == ";"){
           cout << "\n this is the grouped value before pop->" << groupedValue << "<-" << endl;
            if(!groupedValue.empty() ){
               groupedValue.pop_back(); // gets rid of space at end
             cout << "\n this is the grouped value after pop->" << groupedValue << "<-" << endl;
             tokens.push_back(new User_Cmnds(groupedValue));
            }
           tokens.push_back(new Colon());
           cout << endl << tokens.back()->getARGValue() << endl;
           groupedValue = ""; //resets string for use after cmnd
           found_connector = true;
       }

   }while (cmdInput);
    cout << "\n -----------------------------------------this is after parsing -----------------------\n" ;
    if( (found_connector == false) || (!groupedValue.empty()) ){

        if(!groupedValue.empty()){
        cout << "\n this is the grouped value before pop->" << groupedValue << "<-" << endl;
        groupedValue.pop_back(); // gets rid of space at end
        cout << "\n this is the grouped value after pop->" << groupedValue << "<-" << endl;
        tokens.push_back(new User_Cmnds(groupedValue));
        }
        cout << "\n this is after all cmnds are proceesed \n";
        cout << endl << tokens.back()->getARGValue() << endl;
    }
    // else if(!groupedValue.empty()){
    //     tokens.push_back(new User_Cmnds(groupedValue));
    //     cout << "\n this is after all cmnds are proceesed \n";
    //     cout << endl << tokens.back()->getARGValue() << endl;
    // }

    return;
}

//  void Parser::infix_to_postfix(vector <ARGBase*>& tokens){//doesn not take () yet
//     // stack<ARGBase*> non_operators; //aka output
//     // stack<ARGBase*> operators; // 

//     // for(int i = 0; i < tokens.size(); i++){
//     //     //no white space is in the token vecotr
//     //     //checking if operator is present
//     //     //presedence for operators is the same except ; separates an and ()
//     //     if(tokens.at(i)->getARGValue().at(0) == '('){//checks for ()
//     //         operators.push(new Parenth("("));

//     //     }
//     //     if(tokens.at(i)->is_operator() != true){ //meaning some command
//     //         non_operators.push(tokens.at(i));
//     //         cout << "this token was pushed to non_op queue:->" << tokens.at(i)->getARGValue() << "<-" << endl;
//     //     }


//     // }


//  }

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
   // tokenize_each_input(cmdInput, tokens) ;
   tokenize_grouping(cmdInput, tokens);

   cout << "_______________________________" << endl << "this is after tokenizing\n";
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


