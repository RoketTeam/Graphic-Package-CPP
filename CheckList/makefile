# Define required macros here
SHELL = /bin/sh

OBJS =  main.o
CFLAG = -static
CC = x86_64-w64-mingw32-g++ 
INCLUDE = ListItem.cpp CheckList.cpp main.cpp 

All:
	x86_64-w64-mingw32-g++ -static ListItem.cpp CheckList.cpp main.cpp -o main.exe
	wineconsole main.exe

clean:
	-rm -f *.exe

