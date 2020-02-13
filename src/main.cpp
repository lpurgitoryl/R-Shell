#include "../header/Parser.h"
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <wait.h>
#include <cstring>
#include <iostream>

using namespace std;

void prompt(){
    std::cout << "\n$ ";
}





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
    char** argv = input.create_aray(tokens);



    // for(int i = 0; i < tokens.size(); i++){
    //     cout << tokens.at(i)->getARGValue() << " ";
    //    // char tochar[tokens.at(i)->getARGValue().size() + 1];
    //    // strcpy(tochar, tokens.at(i)->getARGValue().c_str());
    //     //*argv[i][i] = *tochar;
    // }

    
  

}

 