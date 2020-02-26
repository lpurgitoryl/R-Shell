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
using namespace std;

void eval(char** args){

    pid_t childProcess = fork();
    int childStatus; //to be used by wait
    pid_t childProcessID;
    
    waitpid(childProcess, &childStatus, 0);

    if( childProcess < 0){
        cout << "Child process could not be created\n";

        exit(EXIT_FAILURE); 
    }
    else if( childProcess == 0){
        
       execvp(*args, args); //execute
        //while 
    }
    else {
        //wait child
        childProcessID = wait(&childStatus); //
        // use wifext,
      // if(  WIFEXITED(childStatus) > 0){

       //}; //
      //  cout << "Parent: Child " <<  childProcessID << " exited with status = " << childStatus << endl;
    }
    //return childStatus;
}


#endif