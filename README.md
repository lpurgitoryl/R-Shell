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

This will be done by using **enter class brakedown here**.

The general structure of the commands avalible for input will be in this form.
```
$ executable [argumentList] [connector] [executable] ...
```

## OMT Diagram

**after uploading the image, ill add a link here**

## Class Description
First thing after organizing 

## Protoypes/Research 

- `fork()`
- `execvp()`
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