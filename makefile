
CC = g++ # Compiler Type

SRC_DIR = ./src # Directory of the .cpp files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) # All .cpp files in SRC_DIR

all: chess # Default compiled file

chess: $(SRC_FILES) #Compiles all .cpp files in SRC_FILES, and outputs to chess
	$(CC) -o $@ $^ 

clean: # Removes chess
	rm -f chess
