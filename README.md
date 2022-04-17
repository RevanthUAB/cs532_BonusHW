# Project Title: My Shell
## Bonus Homework

# Project Description

The aim of the bonus project is to develop a shell with the given commands where it has to work as a shell and provide the output based on the command provided.

This shell has to run the following commands hello, fibonacci, list, cd, help, quit, history. With each of these commands has their own functions.


## Prerequisites/dependencies 

Requirements for the software and other tools to build, test and push
- [Example 1]GCC compiler
- [Example 2]C language

## How to run test cases

To compile the files 
    $ gcc -Wall -o main.o main.c -c
    $ gcc -Wall -o commands.o commands.c -c
    $ gcc -Wall main.o commands.o -o uab_sh
or simply
    $ make
        gives you the output with filename: uab_sh

## Sample test cases

To run the program:
  $ ./uab_sh

These are the following commands:
  hello
  fibonacci
  list
  cd
  help
  quit
  history

# Sample Session

uab_sh > hello
Hello World!.....
uab_sh > fibonacci 6
The first 6 values: 0 1 1 2 3 5
uab_sh > fibonacci
How many elements you want to display: 8
The first 8 values: 0 1 1 2 3 5 8 13
uab_sh > list
README.md  commands.c  commands.o  main.c  main.o  makefile  myhead.h  uab_sh  uab_sh.log
uab_sh > help

  hello
  fibonacci
  list
  cd
  help
  quit
  history


These are the available commands and
displaying how the available functions are expected to work in the shell created.

>hello: This command will print the 'Hello World.'

>fibonacci: This command will take or ask for the integer argument as input
and display number of fibonacci series given as input.

>list: This command will display the files in the current folder.

>cd: This command will help you change your current directory location.

>help: This command will display the information about the commands
and how they are expected to work.

>quit: This command will terminate the uab_sh shell.

uab_sh > history

hello
fibonacci 6
fibonacci
list
help
history

uab_sh > cd ..
uab_sh > pwd
/mnt/c/Users/rkari/Downloads/sem2/sysprg/hw/Bonus_HW
uab_sh > cd submit
uab_sh > pwd
/mnt/c/Users/rkari/Downloads/sem2/sysprg/hw/Bonus_HW/submit
uab_sh > quit

# Author
 - **Revanth Kari** - *CS 532* - 
  [GitHub](https://github.com/RevanthUAB/cs532_BonusHW)


# Acknowledgment

  - Previous lab and homework resources provided by the lecture are used.

[//]: #
  [Linus]:<https://linux.die.net/man/3/execvp>
  [Stackoverflow]:<https://stackoverflow.com/questions/40051500/make-main-o-error-1/40051570>
  [Solver]:<https://solver.assistedcoding.eu/makefilegen>
  [Javapoint]:<https://www.javatpoint.com/array-of-structures-in-c#:~:text=An%20array%20of%20structres%20in,entities%20of%20different%20data%20types.>

