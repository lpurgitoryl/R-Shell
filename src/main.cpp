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

void eval(char** val);



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
        exit(0);
    }


    // char** argv = input.create_aray(tokens);

    // eval(argv);

    //cout << argv[0] << endl;

    // for(int i = 0; i < tokens.size(); i++){
    //     cout << tokens.at(i)->getARGValue();
       
    // }
    pid_t child;
int cstatus; /* Exit status of child. */
pid_t c; /* Pid of child to be returned by wait. */
char **args = input.create_array(tokens); /* List of arguments for the child process. */
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


void eval(char** val){
    pid_t forkVal = fork();
    int status;
    cout << "here" << endl;
    execvp(val[0], val);
    //< 0 == fail
    //= 0 == child process
    //>0 id and parent will execute


        // if(forkVal < 0){
        //     cout << "error with creating child" << endl;
        //     exit(1);
        // }
        // else if(forkVal == 0){
        //     //in parentS
        //     if(execvp(*val, val) < 0){
        //         cout << "error with cmnd" << endl;
        //         exit(1);
        //     }
        //     execvp(*val, val);
        // }
        // else{
        //     wait(NULL); //terminate
        //     return;
        // }
    

}

 