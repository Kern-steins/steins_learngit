example : main.o 
	gcc main.o -o main
main.o : main.cpp
	gcc -g -Wall -Og -rdynamic -c main.cpp
