#include "../header/Parser.h"
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <wait.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include "../header/executor.h"

using namespace std;

void prompt(){
    std::cout << "$ ";
}

//void eval(char** char_array);

//MAIN MENU FOR USER

int main(){
    while(1){
        //starts prompt and gets line
        prompt();
        //fork

        string userInput;
        getline(cin, userInput);
        Parser input(userInput);

        // //end of input
        // //start of token vector


        vector<ARGBase*> tokens = input.parse();
        
        if( (tokens.size() == 1 && tokens.at(0)->getARGValue() == "exit") ){
           // cout << "exited shell" << endl;
            exit(1);
        }

        // for(int i = 0; i < tokens.size(); i++){//tester for correct values in tokens
        //     cout << "this is token number: " << i << " and the value is " << endl;
        //     cout << "value here ->" << tokens.at(i)->getARGValue() << "<-" << endl;
        
        // }
        cout << "this is the token vector size: " << tokens.size() << endl;


        //  char** argv = input.create_array(tokens);

        //  eval(argv);
    }

return 0;

}


 
