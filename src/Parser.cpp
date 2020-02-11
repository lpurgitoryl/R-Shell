#include <../header/Parser.h>

ARGBase* Parser::tokenize(std::string vals, vector <ARGBase*>& tokens ){
    

}

vector<ARGBase*> Parser::parse(){
    vector <ARGBase*> tokens;
    string vals;
    while( cmdInput >> vals){
        tokenize(vals, tokens);
    }



}