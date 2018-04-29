# Define required macros here
SHELL = /bin/sh

OBJS =  main.o
CFLAG = -static
CC = x86_64-w64-mingw32-g++ 

All:
	make clean
	make TextBox
clean:
	-rm -f *.exe

TextBox:
	x86_64-w64-mingw32-g++ -static TextBox.cpp Source.cpp -o TextBox.exe
	wineconsole TextBox.exe
