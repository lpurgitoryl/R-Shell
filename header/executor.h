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
    numSpaces++; //to account for the word after the space

    std::cout << "this is oginal size " << numSpaces  << endl;
    cmnds = (char**) malloc((numSpaces + 1) * sizeof(char*)); //allocates "lenghth" of 2d array, adds 1 for null char

//HERE IS WHERE WE DECIDE WHERRE TO ALLOCATE 


   // cout << tokens.size() << " this is token size \n";
    //cout << "before for loop" << endl;
    int index = 0;
    string temp = "";

    for (int i = 0; i < tokens.size() ; i++){
        if(tokens.at(i) != ' '){
            temp += tokens.at(i);//ads to string in order to get word 
            std::cout << "this is temp value->" << temp << "<-\n";
        }
        else{
            if(index < numSpaces) {  
                std::cout << "this is index " <<  index << endl;
                cmnds[index] = (char*) malloc( temp.size() * sizeof(char)); //allocates space for string @ index
                char * vals = const_cast<char*>(  temp.c_str());
                strcpy(cmnds[index], vals);
                std::cout << "this is the value in the aray->" << cmnds[index] << "<-\n";
                
                index++;
                std::cout << "this is new index " <<  index << endl;

                temp = "";
            }
        }
      //  cout << cmnds[i] << endl;
    } 

    std::cout << "\nIndex after loop allocation " << index << endl;

    if(temp != ""){
        std::cout << "this is index after loop\n" << index << endl;

        cmnds[index] = (char*) malloc( temp.size() * sizeof(char)); //allocates space for string @ index
        char * vals = const_cast<char*>(  temp.c_str());
        strcpy(cmnds[index], vals);
        std::cout << "this is the value in the aray->" << cmnds[index] << "<-\n";
        index++;
    }

    std::cout << "\n size of array is " << numSpaces + 1 << endl;
    cmnds[numSpaces] = NULL; //creates end with null
   // cout << "this is last value" << cmnds[numSpaces + 1] << endl;
   std::cout << "\nthese are the values in the array\n";
   for(int i = 0 ; i <= numSpaces ; i++){
       if (cmnds[i] != NULL)
       std::cout << cmnds[i] << "\n";
   }
    return cmnds;

}
int eval(char** args){ // returns 1 for true and 0 for false

    pid_t childProcess = fork();
    int childStatus; //to be used by wait
    pid_t childProcessID;
    
    waitpid(childProcess, &childStatus, 0);

    if( childProcess < 0){
        std::cout << "Child process could not be created\n";

        exit(EXIT_FAILURE); 
    }
    else if( childProcess == 0){
        
       std::cout << "this is process\n" << endl;
       if(execvp(*args, args) == -1){
           perror("exec");
           return 0; //false
       } ; //execute
        
    }
    else {
        //wait child
        childProcessID = wait(&childStatus); //
        // use wifext,
    //   if(  WIFEXITED(childStatus) > 0){
    //          return childStatus;
    //     }; //
      //  cout << "Parent: Child " <<  childProcessID << " exited with status = " << childStatus << endl;
    }
    return 1; //true
    //return childStatus;
}


bool runTest(string test){
  
    string sub = test.substr(0, 4);
    std::cout << "this is subtr->" << sub << "<-" << endl << "this is test string->" << test << "<-" << endl;

    if( sub != "test" && test.at(0) != '[' ){
       std::cout << "\nno test function" << endl;
       return false;
    }
    else{
        return true;
    }
    return false;
    //if -e check file directory exits, deafult
    //if -f check if file/directory exist and is regular file
    //if -d checks if file/directory exists and is a directory
    //use S_ISDIR AND S_ISREG MACROS
    //EX. test -e test/file/path ,  [ -e test/file/path ] 
    //stat returns -1 if error
   
   // struct stat file;


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

   std:: cout << "this is root " << root->getARGValue() << endl;
    //root->can_execute();
    char** cmnd = create_array(root->getARGValue());
    std::cout << "THIS IS CMND " << cmnd[0] << endl;
    // if ( runTest();
   std::cout <<  eval(cmnd) ;
    // if( eval(cmnd) > 0 )
    //     cout << "error";


return;

}


#endif