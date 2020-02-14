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
    char * cmnds[tokens.size() - 1];
    for (int i = 0; i < tokens.size() ; i++){
        cmnds[i] = const_cast<char*>(tokens.at(i)->getARGValue().c_str());
        cout << cmnds[i] << endl;
    } 
    cmnds[tokens.size()] = NULL;
    
    return cmnds;


    //stop here

    // cout << tokens.size() << " this is token size \n";
    // //cout << "before for loop" << endl;
    
    //  char **argv = (char**) malloc(tokens.size() * sizeof(char*));

    //  cout << "\n before for loop \n";

    // for(int i = 0; i < tokens.size(); i++){
    //     cout << "print index: " <<  i << endl;
    //     cout << "outputting tokens: " ;//<< tokens.at(i) << " " << endl;
    //    // cout << "using priv member " << ARGValue << endl;
    //     cout << tokens.at(i)->getARGValue() << endl;
    //     cout << "-------------------------------------" << endl;
    //     string value = tokens.at(i)->getARGValue();
    //     cout << value << endl;
    //     cout << "---------------------------------" << endl;
    //     cout << "this here is the test char" << endl;
    //     char* test = const_cast<char*>(tokens.at(i)->getARGValue().c_str());
    //    //char* tochar;
    //    //strcpy(tochar, value.c_str());
    //      argv[i] = test;
    //    cout << "-------------------------------------" << endl;
    //    cout << test << "here is value for test" <<endl;
    // }
    // for (int i = 0; i < 3 ; i++) {
    //     cout << "here";
    //     printf("%s ", argv[i]);
    // }

}

vector<ARGBase*> Parser::parse(){
    vector <ARGBase*> tokens;
    // 
    tokenize(cmdInput, tokens) ;
    
return tokens;

}


