#include <wait.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

#include "../header/executor.h"


#include "../header/Parser.h"

using namespace std;

void prompt(){
    std::cout << "$ ";
}

bool runTest(string test){ // true = 0, false = 1
  
   // cout << "test size" << test.size() << endl;
     if(test.size() >= 4){
         //   cout << "greater than 4" << endl;
            string sub = test.substr(0, 4);
        //    std::cout << "this is subtr->" << sub << "<-" << endl << "this is test string->" << test << "<-" << endl;
            if( sub != "test" && sub.at(0) != '['){
        //    std::cout << "\nno test function for size 4 or greater" << endl;
            return false;
            }
       // return true;
    }

    else if( (test.at(0) == '[' && test.at(test.size() -1 ) != ']') || (test.at(0) != '[' && test.at(test.size() -1 ) != ']') ){

        std::cout << "\nno test function in general either because of bracket mismatch or key word missing " << endl;
        return false;
       // }
    }
    // at this point it is a test cmnd bc it passed backet/ test check
    struct stat buff;

    string flag = "";
    string restofString = "";

    //cout << test.at(0);

    //get flag and file path
    //bool noflag = false;

    if(test.at(0) == '['){ //flag will be at 2,3
        flag = test.substr(2,2);
        int testSize = test.size() - 8;
        restofString = test.substr(5, testSize + 1 );
        // if(flag != "-e" || flag != "-f" || flag != "-d"){
        //     noflag = true;
        //     testSize = test.size() - 4;
        //     restofString = test.substr(2, testSize );
        // }
       // cout <<  "this be flag " << flag << endl;
       // cout << "this is path*->" << restofString << "<-" << endl;
    }
    else{
        flag = test.substr(5,2);
        int testSize = test.size() - 6 ;
        restofString = test.substr(8, testSize );
        // if(flag != "-e" || flag != "-f" || flag != "-d"){
        //     noflag = true;
        //     testSize = test.size() - 4;
        //     restofString = test.substr(5, testSize );
        // }
       // cout << "this is path->" << restofString << "<-" << endl;
    }

    //end get flag

    char * filePath = new char [restofString.length()+1];
    std::strcpy (filePath, restofString.c_str());
    
    int statvalue = stat( filePath, &buff); //On success, zero is returned. On error, -1 is returned, and errno is set appropriately.
    //char filePath = restofString.c_str() ;
  

    //cout << "this is stat value "<< statvalue << endl;
    //cout << "this is stat value "<< stat( filePath, &buff) << endl;
    //cout << stat( "names.txt" , &buff) << endl;
    // if(statvalue < 0){
    //    perror("no such file");
    //    return false;
    // }

    if(flag == "-e" ){
        if(statvalue < 0){
            perror("no such file");
            return false;
        }
        //cout << "here"<< endl;
            return true;  
    }
    else if ( flag == "-f"){
        if(S_ISREG(buff.st_mode)){ //if zero its false
            return true;
        }
        return false;
    }
    else if( flag == "-d"){
         if(S_ISDIR(buff.st_mode)) {
            return true;
        }
        return false;
    }

    else{
        cout << "\nno flag\n";
        return false;
    }
    
    //if -e check file directory exits, deafult
    //if -f check if file/directory exist and is regular file
    //if -d checks if file/directory exists and is a directory
    //use S_ISDIR AND S_ISREG MACROS
    //EX. test -e test/file/path ,  [ -e test/file/path ] 
    //stat returns -1 if error
   
   // struct stat file;

    return true;

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

   //std:: cout << "this is root " << root->getARGValue() << endl;
    //root->can_execute();
    //char** cmnd = create_char_array(root->getARGValue());
    //std::cout << "THIS IS CMND " << cmnd[0] << endl;
    //checks if key word or bracket
    string testKey = "";
    if(root->getARGValue().size() >= 4){
        testKey = root->getARGValue().substr(0,4);
    }
    if(root->getARGValue().at(0) == '[' || testKey == "test" ){
        bool testVal = runTest(root->getARGValue());

        if(testVal){
            cout << "(true)" << endl;
        }
        else{
            cout << "(false)" << endl;
        }

    }else{
        
        // if(!root->get_left()){
        //     runCommands(root->get_left());
        // }
        root->can_execute();
        
        // if(!root->get_right()){
        //     runCommands(root->get_right());
        // }
    }
    // if ( !runTest(root->getARGValue())) {

    //     cout << "\nno test here in run cmnds check\n";
    //     cout << runTest(root->getARGValue()) << " this is failure for test func\n";
    // }
    // else if(runTest(root->getARGValue())){
    //      cout << "(true)" << endl;
    //      return;
    // }


return;

}

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
        // cout << "this is the token vector size: " << tokens.size() << endl;


         //char** argv = input.create_array(tokens);

         //eval(argv);

        vector<ARGBase*> temp = input.infix_to_postfix(tokens);
       // cout << "this is the token vector size: " << tokens.size() << endl;
    //    for (int i = 0; i < temp.size() ; i++){
    //        cout << temp.at(i)->getARGValue();
    //    }
    //stack<ARGBase*>pull;
        input.create_tree_vector(temp);
        //cout << "this should run cmnd\n" << endl;
        //input.getRoot()->can_execute();
        runCommands(input.getRoot());
        //runTest(input.getRoot()->getARGValue() );
       // ARGBase* start = temp.at(0);
     //  printInOrder(root);
        //  char** argv = input.create_array(tokens);

        //  eval(argv);
    }

return 0;

}