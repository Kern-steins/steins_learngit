SHELL := /bin/bash

INC = $(wildcard ./inc/*.h)
MAIN_SRC = $(wildcard ./src/main.cpp)
SRC_ALL = $(wildcard ./src/*.cpp ./src/*.c)
SRC = $(filter-out $(MAIN_SRC), $(SRC_ALL))
TRASH = $(wildcard ./src/*.c[^p]* ./src/*.cpp?* ./inc/*.h?* *.o main)
EMPTY=

main : $(MAIN_SRC)
	g++ $(MAIN_SRC) -Wall -Og -g -L. -lsteins -Iinc -o main

lib: $(SRC) $(INC) 
	@make clean
	@echo "building lib file"
	gcc -c $(SRC)
	ar rs libsteins.a $(wildcard *.o)
	make clean

indent: $(SRC_ALL) $(INC)
	-astyle --style=kr $(SRC_ALL)
	-astyle --style=kr $(INC)

.PHONY: clean
.PHONY: lib 

clean:
ifeq ($(TRASH),$(EMPTY))
	@echo "No trash"
else
	@rm $(TRASH)
	@echo "clean done"
endif
