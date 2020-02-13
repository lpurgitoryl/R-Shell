#include "../header/Parser.h"

// void Parser::remove_newlineprompt(){
//     cout << cmdInput << " : orignal input\n promnt gotten rid of";
//     string firstTwo = cmdInput.substr(0,1);
//     if( firstTwo == "$ "){
//         cmdInput = cmdInput.substr(2);
//     }
//     cout << cmdInput << "\n";

// }

void Parser::is_connectors(vector <ARGBase*>& tokens){
  
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
 void Parser::find_connectors(){
     cout << "here" << endl;
 }

ARGBase* split_up(){
    return 0;
}

// void Parser::prompt(){
//     cout << "\n$ ";
//     string userInput;
//     getline(cin, userInput);
//     cout << userInput;
//     cmdInput >> userInput;
// }

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

vector<ARGBase*> Parser::parse(){
    vector <ARGBase*> tokens;
    // 
    tokenize(cmdInput, tokens) ;
    
return tokens;

}


