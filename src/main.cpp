#include "../header/Parser.h"

void prompt();

//MAIN MENU FOR USER

int main(){

    prompt();
    string userInput;
    getline(cin, userInput);
    cout << userInput;
    Parser input(userInput);


   


}



void prompt(){
    cout << "\n$ ";
}

