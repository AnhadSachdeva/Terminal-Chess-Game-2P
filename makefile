# makefile runs the chess program in the terminal

CC = g++

SRC_DIR = ./src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

all: chess

chess: $(SRC_FILES)
	$(CC) -o $@ $^


# deletes the files chess
clean:
	rm -f chess
