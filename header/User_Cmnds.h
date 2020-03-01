#ifndef __CMNDS__
#define __CMNDS__

//#include "executor.h"
#include "ARGBase.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <sys/stat.h>

using namespace std;

// will do fork, execvp, waitpid
class User_Cmnds : public ARGBase {
   
    protected:
        ARGBase* left = 0;
        ARGBase* right = 0;
        bool op = false; //shows if operator or not for precendce
    
    public:
        User_Cmnds(ARGBase* lef, ARGBase* righ, std::string value) : ARGBase(value), left(left), right(right){}
        User_Cmnds(std::string value): ARGBase(value){}

        void set_left(ARGBase* lef){
        left = lef;
        }

        void set_right(ARGBase* righ){
        right = righ;
        }
            ARGBase* get_right(){
        return this->right;
        }
        ARGBase* get_left(){
        return this->left;
        }
        

        bool is_operator(){
            return this->op;
        }
    
    char** create_char_array(string tokens){
        char ** cmnds = NULL;
       //TODO: FIND LENGHT OF 2D VIA SPACES
        int numSpaces = 0;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens.at(i) == ' '){
                numSpaces++;
            }
        }
        numSpaces++; //to account for the word after the space

       // std::cout << "this is oginal size " << numSpaces  << endl;
        cmnds = (char**) malloc((numSpaces + 1) * sizeof(char*)); //allocates "lenghth" of 2d array, adds 1 for null char

    //HERE IS WHERE WE DECIDE WHERRE TO ALLOCATE 


    // cout << tokens.size() << " this is token size \n";
        //cout << "before for loop" << endl;
        int index = 0;
        string temp = "";

        for (int i = 0; i < tokens.size() ; i++){
            if(tokens.at(i) != ' '){
                temp += tokens.at(i);//ads to string in order to get word 
            //    std::cout << "this is temp value->" << temp << "<-\n";
            }
            else{
                if(index < numSpaces) {  
                //    std::cout << "this is index " <<  index << endl;
                    cmnds[index] = (char*) malloc( temp.size() * sizeof(char)); //allocates space for string @ index
                    char * vals = const_cast<char*>(  temp.c_str());
                    strcpy(cmnds[index], vals);
                //    std::cout << "this is the value in the aray->" << cmnds[index] << "<-\n";
                    
                    index++;
                //    std::cout << "this is new index " <<  index << endl;

                    temp = "";
                }
            }
        //  cout << cmnds[i] << endl;
        } 

        //std::cout << "\nIndex after loop allocation " << index << endl;

        if(temp != ""){
        //    std::cout << "this is index after loop\n" << index << endl;

            cmnds[index] = (char*) malloc( temp.size() * sizeof(char)); //allocates space for string @ index
            char * vals = const_cast<char*>(  temp.c_str());
            strcpy(cmnds[index], vals);
        //    std::cout << "this is the value in the aray->" << cmnds[index] << "<-\n";
            index++;
        }

        //std::cout << "\n size of array is " << numSpaces + 1 << endl;
        cmnds[numSpaces] = NULL; //creates end with null
        // cout << "this is last value" << cmnds[numSpaces + 1] << endl;
        //std::cout << "\nthese are the values in the array\n";
        // for(int i = 0 ; i <= numSpaces ; i++){
        //     if (cmnds[i] != NULL)
        //     std::cout << cmnds[i] << "\n";
        // }
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

     bool can_execute(){//0 is false from eval , 1 is true
            char** test = create_char_array(this->ARGValue);
            if(eval(test) == 0){
                cout << "0" << endl;
                return false;
            }
            cout << "1" << endl;
            return true;
    }
        



};




#endif
