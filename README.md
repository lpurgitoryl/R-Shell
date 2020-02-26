# CS 100 Programming Project
**Winter Quarter 2020**
>Authors:  
Nicole Garcia, 862111704   
Hung Le, 862063377  


## Introduction
The R'Shell (command shell written in C++) will be able to preform the following:

1. Print a command prompt starting with `$`.
2. Read in a line of command(s) and/or connector(s) from user input.  

3. Execute the appropriate commands using `fork`, `execvp`, and `waitpid`.
4. Repeat the above until an exit command is executed.  

This will be done by using **enter class breakdown here**.

The general structure of the commands avalible for input will be in this form.
```
$ executable [argumentList] [connector] [executable] ...
```

## OMT Diagram
    
![OMT Diagram](https://github.com/cs100/assignment-teamteam/blob/master/images/OML%20DIagram.jpg?raw=true)



## Class Description
![Breakdown of classes to be impelented](https://camo.githubusercontent.com/296f638fb195719e6d6affd90adf4e1e82d9f604/68747470733a2f2f692e6779617a6f2e636f6d2f30653965393836316135393235666636363436356631356231643162356363332e706e67)

For the OMT DIAGRAM, the fork class is currently combined with exec class
 
1. Abstract `ARGBase` class
    * This class will have virtual function that takes in a string as a basline for user input for the rest of the derived classes (composite pattern implementation). The abstract class has an execute class that the derived classes will use in order to determine whether a command will run or not. Has the functions getARGValue in order to obtain the string. Newly added setters and getters in order to set the pointers of it's children. Has a virtual execute function for the derived classes. 
2. `Interface` : Contains or prompt for the user to run commands on.
    * `User_commands` : this is whatever the user wants to run
    *  `Connector_class` : any connector that a user will add to a line
    * `Exe_class` : will do any syscalls
3. `Parser` 
	*Parser will parse the user input into string that will then be stored in a vector called tokens that will hold ARGBase pointers. This is also how we change the string into **char in order to run execvp.

4. `User_commands`
    	*will perform any commands that the user will put in. Has an execute function from its parent class to see if the user command is valid and will run.
5. `Connector_class`
	*will perform the logics for and, or, and semicolon, Currently cannot do logic for multiple arguments, also makes a constructor with ARGBASE pointing left and right. Contains a execute function which is derived from its parent class.
    
6. `Exe_class`
	*performs fork(), execvp(), and waitpid(), in its own header file. Has the function eval to perform these tasks.
    

## Protoypes/Research 

- `fork()`
    * should give 2^n proccesses. Code below outputs the children and parents based on decremtation.
```
 for(int i = 0; i < value; i++){
    fork();
    cout << i << endl;
    //value--;
    }
```
- `execvp()`
    * takes in char input arrays to execute commands. For example, the `cmd` array is the intial instruction, while the `argv` is the arguemnt beinf used.
     * In use for the assigment the parser will need to identify the diffrent between the executable and the arguemnt, while using the connectors to preform the next task.

```
char *cmd = "echo";
char *argv[5]; // this length can be changed 

execvp(cmd, argv);

```  

- `waitpid()`
- `Parse()`

## Development and Testing Roadmap

Below are some development issues.  
[1. Develop the interface to take commands ](https://github.com/cs100/assignment-teamteam/issues/1#issue-556420534)   
[2. Work on parsing for the commands](https://github.com/cs100/assignment-teamteam/issues/2#issue-556421562)  
[3. test parsing](https://github.com/cs100/assignment-teamteam/issues/3#issue-556422455)  
[4. work on basic commands such as `ls`, `mkdir`, and `exit`](https://github.com/cs100/assignment-teamteam/issues/4#issue-556422892)  
[5. unit test on basic commands](https://github.com/cs100/assignment-teamteam/issues/5#issue-556423312)  
[6. Connector functionality and testing ](https://github.com/cs100/assignment-teamteam/issues/6#issue-556424991) 
[7. Retest basic commands with connectors](https://github.com/cs100/assignment-teamteam/issues/7#issue-556425469)  
[8. `fork()` functionality and testing](https://github.com/cs100/assignment-teamteam/issues/8#issue-556425788)  
[9. `execvp()` and `waitpad()` functionality and testing](https://github.com/cs100/assignment-teamteam/issues/9#issue-556426529)  
[10. Testing of functionality with basic commands, connectors, etc..](https://github.com/cs100/assignment-teamteam/issues/10#issue-556426755)
