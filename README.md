# Mini Shell File System Simulator (C)

## Overview
This project simulates a simple terminal file system using a linked-list tree structure.
It was built to practice data structures, pointer manipulation, and command parsing in C.

## Build
gcc main.c options.c -o minishell

## Run
./minishell

## Commands
mkdir <name>   → create directory in current path  
rm <name>      → remove directory  
vd <path>      → view relative navigation; Path options: (../ or ./)  
APATH          → print absolute path  
q              → quit program  

## Concepts Learned
- Linked list   
- Tree structures using parent/child/sibling pointers  
- Dynamic memory management  
- Terminal input buffering  

## Future Improvements
- Error handling for invalid commands  
- File support (not only folders)  
- Improved shell prompt  
