#include <wait.h>
#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "../header/executor.h"


#include "../header/Parser.h"

using namespace std;

void prompt(){
    std::cout << "$ ";
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
       cout << endl;
    //    for (int i = 0; i < temp.size() ; i++){
    //        cout << temp.at(i)->getARGValue();
    //    }
    //stack<ARGBase*>pull;
        input.create_tree_vector(temp);
        cout << "\n this should run cmnd\n" << endl;

       runCommands(input.getRoot());
       // runTest(input.getRoot()->getARGValue() );
       // ARGBase* start = temp.at(0);
     //  printInOrder(root);
        //  char** argv = input.create_array(tokens);

        //  eval(argv);
    }

return 0;

}