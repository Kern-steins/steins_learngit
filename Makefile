OUT_FILE = $(wildcard *.o)
INC = $(wildcard ./inc/*.h)
SRC = $(wildcard ./src/*.cpp ./src/*.c)
TRASH = $(wildcard ./src/*.c[^p]* ./src/*.cpp?* ./inc/*.h?*)

main : $(OUT_FILE) 
	g++ -o main $(OUT_FILE) 
main.o : $(SRC) $(INC)
	g++ -g -Wall -Og -rdynamic -c $(INC) $(SRC)
indent: $(SRC) $(INC)
	-astyle --style=kr $(SRC)
	-astyle --style=kr $(INC)
clean:
	@echo "cleaning project"
	-rm main *.o
	-rm $(TRASH)	
	@echo "clean completed"
OUT_FILE:
	@echo $(OUT_FILE)

.PHONY: clean
