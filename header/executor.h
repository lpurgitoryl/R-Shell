#ifndef __EXECUTOR___
#define __EXECUTOR__


#include "ARGBase.h"
#include "Colon.h"
#include "Or.h"
#include "And.h"
#include "User_Cmnds.h"
#include "Connector.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include "Parser.h"

using namespace std;


char** create_array(string tokens){
    char ** cmnds = NULL;
//TODO: FIND LENGHT OF 2D VIA SPACES
int numSpaces = 0;

    for(int i = 0; i < tokens.size(); i++){
        if(tokens.at(i) == ' '){
            numSpaces++;
        }
    }

    cmnds = (char**) malloc((numSpaces + 1) * sizeof(char*)); //allocates "lenghth" of 2d array
//HERE IS WHERE WE DECIDE WHERRE TO ALLOCATE 


   // cout << tokens.size() << " this is token size \n";
    //cout << "before for loop" << endl;
    for (int i = 0; i < tokens.size() ; i++){
        cmnds[i] = (char*) malloc( tokens.at(i)->getARGValue().size() * sizeof(char)); //allocates space for string @ index
        char * vals = const_cast<char*>(  tokens.at(i)->getARGValue().c_str());
        strcpy(cmnds[i], vals);
      //  cout << cmnds[i] << endl;
    } 
    cmnds[tokens.size()] = NULL; //creates end with null
    
    return cmnds;

}
int eval(char** args){

    pid_t childProcess = fork();
    int childStatus; //to be used by wait
    pid_t childProcessID;
    
    waitpid(childProcess, &childStatus, 0);

    if( childProcess < 0){
        cout << "Child process could not be created\n";

        exit(EXIT_FAILURE); 
    }
    else if( childProcess == 0){
        
       execvp(*args, args) ; //execute
        
    }
    else {
        //wait child
        childProcessID = wait(&childStatus); //
        // use wifext,
      if(  WIFEXITED(childStatus) > 0){
             return childStatus;
        }; //
      //  cout << "Parent: Child " <<  childProcessID << " exited with status = " << childStatus << endl;
    }
    //return childStatus;
}
void runCommands(ARGBase* root){//tokens are in tree form
    // ARGBase* cur = root;

    // if (cur == nullptr){
    //     return;
    // }
    // runCommands(cur->get_left());
    // //cout << cur->getARGValue();
    // if(cur->getARGValue() == "||" || cur->getARGValue() == "&&" ){
    //     if(cur->getARGValue() == "||"){
    //         if(cur->get_left())
    //     }
    // }
    // char** cmnd = create_array(cur->getARGValue());
    // int executed = eval(cmnd);
    // if( executed < 0 )
    // runCommands(cur->get_right());

    cout << "this is root " << root->getARGValue() << endl;
    char** cmnd = create_array(root->getARGValue());
    cout << "THIS IS CMND " << cmnd << endl;
    // if( eval(cmnd) > 0 )
    //     cout << "error";



}

// void runTest(string test){
//     if(test.at(0) == '['){
//         //stats
           // struct stat file;
            //stat(test, file);
//     }

// }




#endif