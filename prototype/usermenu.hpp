#ifndef __USERMENU_HPP__
#define __USERMENU_HPP__

#include "menu.hpp"
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <string>

class Usermenu : public Menu {
	protected:
	vector<string>commands;
	string input;

	public:
	
	Usermenu();
	
	void run() {
		
	while(input != "exit"){
	cout << "$ ";
	getline(cin,input); 
	
	}
	

}
};

#endif //__USERMENU__HPP__
