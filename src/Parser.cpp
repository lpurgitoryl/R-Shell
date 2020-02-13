#include "../header/Parser.h"


void Parser::find_connectors(vector <ARGBase*>& tokens){
  
   for(int i = 0; i < tokens.size(); i++){
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



//for every space seprate the "words" into user cmds toekns and push to 
//the vector
void Parser::tokenize(istringstream& cmdInput  , vector <ARGBase*>& tokens ){
//      TESTER CODE AS PROOF OF CONCEPT FOR PRINTING  

 do{
       string uptoSpace;
       cmdInput >> uptoSpace;
       if (uptoSpace !="$" && uptoSpace != "&&" && uptoSpace != "||" && uptoSpace != ";" ){
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

char** Parser::create_aray(vector <ARGBase*>& tokens){
     char **argv = (char**) malloc(tokens.size() * sizeof(char*));
    for(int i = 0; i < tokens.size(); i++){
        cout << tokens.at(i)->getARGValue() << " ";
        string value = tokens.at(i)->getARGValue();
        char* tochar;
        strcpy(tochar, value.c_str());
        argv[i] = tochar;
    }
}

vector<ARGBase*> Parser::parse(){
    vector <ARGBase*> tokens;
    // 
    tokenize(cmdInput, tokens) ;
    
return tokens;

}


