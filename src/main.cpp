#include "../header/Parser.h"

void prompt();

//MAIN MENU FOR USER

int main(){

    //starts prompt and gets line
    prompt();
    string userInput;
    getline(cin, userInput);
    //cout << userInput;
    Parser input(userInput);

    //end of input
    //start of token vector
    vector<ARGBase*> tokens = input.parse();

    for(int i = 0; i < tokens.size(); i++){
        // ARGBase* toke = tokens.at(i);
        // toke->getARGValue();
        cout << tokens.at(i)->getARGValue();

    }
}

void prompt(){
    cout << "\n$ ";
}
