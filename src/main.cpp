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


//MAIN MENU FOR USER

int main(){

    //starts prompt and gets line
    prompt();
    //fork

    string userInput;
    getline(cin, userInput);
    Parser input(userInput);

    // //end of input
    // //start of token vector


    vector<ARGBase*> tokens = input.parse();
    //if exit 
    if(tokens.size() == 1 && tokens.at(0)->getARGValue() == "exit"){
        exit(1);
    }

    for(int i = 0; i < tokens.size(); i++){
        cout << "this is token number: " << i << " and the value is " << endl;
        cout << "value here ->" << tokens.at(i)->getARGValue() << "<-" << endl;
       
    }
    // char** argv = input.create_aray(tokens);

    // eval(argv);

    //cout << argv[0] << endl;

    
// pid_t child;
// int cstatus; /* Exit status of child. */
// pid_t c; /* Pid of child to be returned by wait. */
// char **args = input.create_array(tokens); /* List of arguments for the child process. */
//cout << *args[0] << " " << *args[1] << endl;
/* Set up arguments to run an exec in the child process. */
/* (This example runs the "ls" program with "-l" option.) */
//args[0] = "ls"; args[1] = "-l";
//args[2] = NULL; /* Indicates the end of arguments. */
// if ((child = fork()) == 0) { /* Child process. */
// printf("Child: PID of Child = %ld\n", (long) getpid());
// execvp(*args, args); /* arg[0] has the command name. */
// /* If the child process reaches this point, then */
// /* execvp must have failed. */
// fprintf(stderr, "Child process could not do execvp.\n");
// exit(1);
// }
// else { /* Parent process. */
// if (child == (pid_t)(-1)) {
// fprintf(stderr, "Fork failed.\n"); exit(1);
// }
// else {
// c = wait(&cstatus); /* Wait for child to complete. */
// printf("Parent: Child %ld exited with status = %d\n",
// (long) c, cstatus);
// }
// }
return 0;

}



 