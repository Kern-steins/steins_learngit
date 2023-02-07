MAIN_SRC = $(wildcard ./src/main.cpp)
INC = $(wildcard *.h)



main : main.o 
	g++ main.o -o main
main.o : $(MAIN_SRC) 
	g++ -g -Wall -Og -rdynamic -c $(MAIN_SRC)
clean:
	@echo "cleaning project"
	-rm main *.o
	@echo "clean completed"
