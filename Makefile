MAIN_SRC = $(wildcard ./src/main.cpp)
INC = $(wildcard ./inc/*.h)
SRC = $(wildcard ./src/*.cpp ./src/*.c)


main : main.o 
	g++ main.o -o main
main.o : $(MAIN_SRC) 
	g++ -g -Wall -Og -rdynamic -c $(MAIN_SRC)
indent: $(SRC) $(INC)
	-astyle --style=kr $(SRC)
	-astyle --style=kr $(INC)
clean:
	@echo "cleaning project"
	-rm main *.o
	@echo "clean completed"



.PHONY: clean
