#include <../header/Parser.h>

string prompt();


int main(int argc, char* argv){

    prompt();

    Parser input(argc, argv);

}



string prompt(){
    cout << "$";
}

