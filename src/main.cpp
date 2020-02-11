#include "../header/Parser.h"

string prompt();

//MAIN MENU FOR USER

int main(){

    prompt();
    string userInput;
    getline(cin, userInput);
    Parser input(userInput);

}



string prompt(){
    cout << "\n$ ";
}

