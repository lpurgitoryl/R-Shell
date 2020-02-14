#include "../header/Parser.h"
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <wait.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

void prompt(){
    std::cout << "$ ";
}

void eval(char** char_array);

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
    
    if(tokens.size() == 1 && tokens.at(0)->getARGValue() == "exit"){
        cout << "exited shell" << endl;
        exit(1);
    }

    for(int i = 0; i < tokens.size(); i++){
        cout << "this is token number: " << i << " and the value is " << endl;
        cout << "value here ->" << tokens.at(i)->getARGValue() << "<-" << endl;
       
    }

    char** argv = input.create_array(tokens);

    eval(argv);
    }

return 0;

}

void eval(char** args){

    pid_t childProcess = fork();
    int childStatus; //to be used by wait
    pid_t childProcessID;
    
    if( childProcess < 0){
        cout << "Child process could not be created\n";
        exit(1); 
    }
    else if( childProcess == 0){
        execvp(*args, args); //execute
    }
    else {
        //wait child
        childProcessID = wait(&childStatus); 
        cout << "Parent: Child " <<  childProcessID << " exited with status = " << childStatus << endl;
    }

}

 
