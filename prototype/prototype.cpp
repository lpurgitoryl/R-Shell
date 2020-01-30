#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
using namespace std;

void  usingFork(int value){
   for(int i = 0; i < value; i++){
    fork();
    cout << i << endl;
    //value--;
    }
    
}

void usingWaitpid(int value){
     for(int i = 0; i < value; i++){
    cout << value <<endl;

    //value--;
    }
}

void usingExecvp(){
 cout << "hello" << endl;
char *cmd = "echo";
char *argv[5]; // char array need null last location
argv[0] = "hello";
argv[1] = ";";
argv[2] = "echo";
argv[3] = "World!";
argv[4] = NULL;

execvp(cmd, argv);
}

void usingAllThree(){
 cout << "hello" << endl;
}


int main(){
int userInput;

cout << "Select a process by inputting a number 1-4" << endl;
cout << "1- FORK function" << endl << "2- WAITPID function" << endl << 
    "3- EXECVP function" << endl << "4- Testing all functions together" << endl;
cin >> userInput ;
cout << endl;

if(userInput == 1){
    cout << "1 " << endl;
    cout << "this function uses fork() and counts it processes output should be 2^n process" << endl;
    cout << "enter value" << endl;
    int value;
    cin >> value;

    usingFork(value);
}
else if(userInput == 2){
    cout << "2 " << endl;
      cout << "enter value" << endl;
    int value;
    cin >> value;
    usingWaitpid(value);
     }
else if(userInput == 3){
    cout << "3" << endl;
    usingExecvp();


}
else if(userInput == 4){

    cout << "4 " << endl;
    usingAllThree();
}


return 0;
}