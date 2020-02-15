#include "../header/Parser.h"


void Parser::find_connectors(vector <ARGBase*>& tokens){
  
   for(int i = 0; i < tokens.size(); i++){ //searches entire vector and either creates connector or user cmnd tokens
       if( tokens.at(i)->getARGValue() == "&&" ){
           ARGBase* blank = nullptr;
           blank = tokens.at(i);
           tokens.at(i) = new And();
           delete blank;

       }
       else if( tokens.at(i)->getARGValue() == "||" ){
           ARGBase* blank = nullptr;
           blank = tokens.at(i);
           tokens.at(i) = new Or();
           delete blank;

       }
       else if( tokens.at(i)->getARGValue() == ";" ){
           ARGBase* blank = nullptr;
           blank = tokens.at(i);
           tokens.at(i) = new Colon();
           delete blank;

       }
    }
}


ARGBase* split_up(){
    return 0;
}


int Parser::find_comment_index(vector <ARGBase*>& tokens){
    int hash = -1;
     for(int i = 0; i < tokens.size(); i++){
        if( tokens.at(i)->getARGValue() == "#" || tokens.at(i)->getARGValue().at(0) == '#'  ){
            hash = i;
            return hash;
        }
     }
}

 void Parser::remove_comment(vector <ARGBase*>& tokens, int index){
     while(index >= 1){
         cout << "Token to be removed at this index: " << index<< " " << tokens.at(index)->getARGValue() << endl;
         tokens.pop_back();
         index--;
     }
 }
//for every space seprate the "words" into user cmds toekns and push to 
//the vector
void Parser::tokenize(istringstream& cmdInput  , vector <ARGBase*>& tokens ){
//creates token vector from input and then tokenizes to either connector or user cmnd
 do{
       string uptoSpace;
       cmdInput >> uptoSpace;
       if (uptoSpace !="$" && uptoSpace != "&&" && uptoSpace != "||" && uptoSpace != ";" && uptoSpace != ""){
       tokens.push_back(new User_Cmnds(uptoSpace));
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

}

char** Parser::create_array(vector <ARGBase*>& tokens){
    char ** cmnds = NULL;

    cmnds = (char**) malloc((tokens.size()) * sizeof(char*)); //allocates "lenghth" of 2d array
    cout << tokens.size() << " this is token size \n";
    cout << "before for loop" << endl;
    for (int i = 0; i < tokens.size() ; i++){
         cmnds[i] = (char*) malloc( tokens.at(i)->getARGValue().size() * sizeof(char)); //allocates space for string @ index
         char * vals = const_cast<char*>(  tokens.at(i)->getARGValue().c_str());
        strcpy(cmnds[i], vals);
        cout << cmnds[i] << endl;
    } 
    cmnds[tokens.size()] = NULL; //creates end with null
    
    return cmnds;

}

vector<ARGBase*> Parser::parse(){
    vector <ARGBase*> tokens;
    // 
    tokenize(cmdInput, tokens) ;
    // for(int i = 0; i < tokens.size(); i++){//tester for correct values in tokens
    //         cout << "this is token number: " << i << " and the value is " << endl;
    //         cout << "value here ->" << tokens.at(i)->getARGValue() << "<-" << endl;
        
    //     }

    int indexComment = find_comment_index(tokens);
    if(indexComment != -1){
      remove_comment(tokens, indexComment);
    }
    // for(int i = 0; i < tokens.size(); i++){//tester for correct values in tokens
    //         cout << "this is token number: " << i << " and the value is " << endl;
    //         cout << "value here ->" << tokens.at(i)->getARGValue() << "<-" << endl;
        
    //     }
    
return tokens;

}


