#include "../header/Parser.h"

void prompt();

//MAIN MENU FOR USER

int main(){

    //starts prompt and gets line
    prompt();
    //fork

    string userInput;
    getline(cin, userInput);
    Parser input(userInput);

    //end of input
    //start of token vector
    vector<ARGBase*> tokens = input.parse();

    for(int i = 0; i < tokens.size(); i++){
        cout << tokens.at(i)->getARGValue() << " ";

    }
}

void prompt(){
    cout << "\n$ ";
}


//vector <base> tokens
//echo hello
//evecvp(Array, str_c( tokens.at(i)->getVaue() ))
//
//
//
//