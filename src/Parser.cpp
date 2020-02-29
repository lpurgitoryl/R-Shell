
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
    int left_paren = 0;
    int right_paren = 0;
    for (int i = 0; i < tokens.size(); i++){ //checking for correct number of parenthesis, will not run if there is a missing parenthesis
        if (tokens.at(i)->getARGValue() == "("){
            left_paren++;
        }
        else if (tokens.at(i)->getARGValue() == ")"){
            right_paren++;
        }
    }
    if (left_paren != right_paren){
        cout << "missing parenthesis" << endl;
        exit(1);
    }
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
    //cout << "here" << endl;
    for (int i = 0; i <vals.size(); i++){
        cout << vals.at(i)->getARGValue();
    }
    cout << endl;

    // for (int i = 0; i <vals.size(); i++){
    //     reverse(vals.begin(), vals.end());
    // }
    // for (int i = 0; i <vals.size(); i++){
    //     cout << vals.at(i)->getARGValue();
    // }
    //reversing a vector
    return vals;
}
void Parser::printInOrder(ARGBase* cur){
    if (cur == nullptr){
        return;
    }
    printInOrder(cur->get_left());
    cout << cur->getARGValue();
    printInOrder(cur->get_right());
}
void Parser::create_tree_vector(vector <ARGBase*>& tokens){
    //(echo a && echo b) || (echo c && echo d)
    //(echo d && echo c) || (echo b && echo a)
    //|| && echo a echo b && echo c echo d
    //((echo a || echo b) && echo c)
    // &&|| echo a echo b echo c
    //(echo a || echo b) && (echo c || echo d) && (echo e || echo f)
    //&& && || echo a echo b || echo c echo d || echo e echo f
   
   // cout << endl;
//  for (int i = 0; i < tokens.size(); i++){
//      cout << tokens.at(i)->getARGValue();
//  }
    //ARGBase* root;
    ARGBase* temp;
    ARGBase* temp_l;
    ARGBase* temp_r;
  
    stack<ARGBase*>tree;
    
    for (int i = 0; i < tokens.size(); i++){
        if(tokens.at(i)->getARGValue() != "&&" && tokens.at(i)->getARGValue() != "||"){
            tree.push(tokens.at(i));
        }
        else if (i == tokens.size()-1){
            temp = tokens.at(i);
            temp_l = tree.top();
            tree.pop();
            temp_r = tree.top();
            tree.pop();
            temp->set_right(temp_r);
            temp->set_left(temp_l);
            tree.push(temp);
            //root = tree.top();
        }
        else{
            temp = tokens.at(i);
            temp_l = tree.top();
            tree.pop();
           // if(!tree.empty()){
            temp_r = tree.top();
            tree.pop();
            temp->set_right(temp_r);
           // }
            temp->set_left(temp_l);
            tree.push(temp);
        }
    }    
    root = tree.top();
    printInOrder(root);
    //echo a || echo b && echo c
    //&&||echo a echo b echo c
    // echo a || echo b
    //|| echo a echo b
    //|| && echo a echo b && echo c echo d
    //postfix
    //echo d echo c || echo b echo a || &&
    // || echo c echo d
    //echo b echo a ||
    //echo a && (echo b || echo c)
    //echo c echo b || echo a &&
    


    // cout << "here" << endl;
    // root = tree.top();
    // cout << root->getARGValue();
    // cout << root->get_left()->getARGValue();
    // cout << root->get_right()->getARGValue();
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

   
    string groupedValues = "";
    bool flag = true; //if false means connecotr was found
    int endParenth = 0;

     do{
       string uptoSpace;
       cmdInput >> uptoSpace;

       
       string temp = "";

       if (uptoSpace !="$" && uptoSpace != "&&" && uptoSpace != "||" && uptoSpace != ";" && uptoSpace != "" && uptoSpace != "\n"){

       cout << "\nvalue here is not a connector ->" << uptoSpace << "<-" << endl;
           for ( int  i = 0; i < uptoSpace.size(); i++)
           {
               cout << "this is the char->" << uptoSpace.at(i) << "<-\n" << endl;

               if ( uptoSpace.at(i) == '(')
               {
                   tokens.push_back( new Parenth("(")    );
               }
               else if( uptoSpace.at(i) == ')'){
                   endParenth++;
               }
               else{
                   temp += uptoSpace.at(i);
               }
           }
           
        //temp now holds whole word
        groupedValues += temp + " ";

       }
       else if(uptoSpace == "&&"){
           flag = false;
          if(!groupedValues.empty() )
               groupedValues.pop_back(); // gets rid of space at end
             cout << "\n this is the grouped value after pop->" << groupedValues << "<-" << endl;
            
            tokens.push_back(new User_Cmnds(groupedValues));

            if (endParenth > 0)
            {
                do{
                tokens.push_back(new Parenth(")") );
                endParenth--;
                }while(endParenth > 0);
            }

           tokens.push_back(new And());
           groupedValues = ""; //resets string after connector
       }
       else if(uptoSpace == "||"){
           flag = false;

           if(!groupedValues.empty() )
               groupedValues.pop_back(); // gets rid of space at end
             cout << "\n this is the grouped value after pop->" << groupedValues << "<-" << endl;
             
             tokens.push_back(new User_Cmnds(groupedValues));

              if (endParenth > 0)
            {
                do{
                tokens.push_back(new Parenth(")") );
                endParenth--;
                }while(endParenth > 0);
            }

           tokens.push_back(new Or());
           groupedValues = ""; //resets string after connector
       }
       else if(uptoSpace == ";"){
           flag = false;

           if(!groupedValues.empty() )
               groupedValues.pop_back(); // gets rid of space at end
             cout << "\n this is the grouped value after pop->" << groupedValues << "<-" << endl;
             
             tokens.push_back(new User_Cmnds(groupedValues));

              if (endParenth > 0)
            {
                do{
                tokens.push_back(new Parenth(")") );
                endParenth--;
                }while(endParenth > 0);
            }

           tokens.push_back(new Colon());
           groupedValues = ""; //resets string after connector
       }


       //dealing with right parenthentesis

   }while (cmdInput);
     if( (flag == false) || (!groupedValues.empty()) ){

        if(!groupedValues.empty()){
        cout << "\n this is the grouped value before pop->" << groupedValues << "<-" << endl;
        groupedValues.pop_back(); // gets rid of space at end
        cout << "\n this is the grouped value after pop->" << groupedValues << "<-" << endl;
        tokens.push_back(new User_Cmnds(groupedValues));
        }

         if (endParenth > 0)
            {
                do{
                tokens.push_back(new Parenth(")") );
                endParenth--;
                }while(endParenth > 0);
            }
        cout << "\n this is after all cmnds are proceesed \n";
        cout << endl << tokens.back()->getARGValue() << endl;
    }


  // what if no connecotor

    return;
}



// char** Parser::create_array(vector <ARGBase*>& tokens){
//     char ** cmnds = NULL;

//     cmnds = (char**) malloc((tokens.size()) * sizeof(char*)); //allocates "lenghth" of 2d array

//    // cout << tokens.size() << " this is token size \n";
//     //cout << "before for loop" << endl;
//     for (int i = 0; i < tokens.size() ; i++){
//         cmnds[i] = (char*) malloc( tokens.at(i)->getARGValue().size() * sizeof(char)); //allocates space for string @ index
//         char * vals = const_cast<char*>(  tokens.at(i)->getARGValue().c_str());
//         strcpy(cmnds[i], vals);
//       //  cout << cmnds[i] << endl;
//     } 
//     cmnds[tokens.size()] = NULL; //creates end with null
    
//     return cmnds;

// }

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
