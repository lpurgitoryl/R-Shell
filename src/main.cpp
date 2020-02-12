#include "../header/Parser.h"

void prompt();

//MAIN MENU FOR USER

int main(){

    prompt();
    string userInput;
    getline(cin, userInput);
    cout << userInput;
    Parser input(userInput);
    // Parser startMenu();
    // startMenu().prompt();



   


}

void prompt(){
    cout << "\n$ ";
    string userInput;
    getline(cin, userInput);
    cout << userInput;
}
