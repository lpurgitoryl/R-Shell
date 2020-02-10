#include <../header/Parser.h>

string prompt();


int main(){

    prompt();
    string userInput;
    getline(cin, userInput);
    Parser input(userInput);

}



string prompt(){
    cout << "\n$ ";
}

