#include "../header/Parser.h"

// void Parser::remove_newlineprompt(){
//     cout << cmdInput << " : orignal input\n promnt gotten rid of";
//     string firstTwo = cmdInput.substr(0,1);
//     if( firstTwo == "$ "){
//         cmdInput = cmdInput.substr(2);
//     }
//     cout << cmdInput << "\n";

// }

bool Parser::is_connectors(){
  return true;
   
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
void Parser::tokenize(istringstream& cmdInput  , vector <ARGBase*>& tokens ){
   do{
       string uptoSpace ;
       cmdInput >> uptoSpace;
       if (uptoSpace !="$"){
       tokens.push_back(new User_Cmnds(uptoSpace));
       }

   }while (cmdInput);
   

}

vector<ARGBase*> Parser::parse(){
    vector <ARGBase*> tokens;
    
   // remove_newlineprompt();
     tokenize(cmdInput, tokens) ;
     string value;

     for(int i = 0; i < tokens.size() ; i++){
         value =  tokens.at(i)->getARGValue();
         cout << value;
         }

    
return tokens;


}
