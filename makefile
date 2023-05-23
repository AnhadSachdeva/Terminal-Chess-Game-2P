CC = g++

SRC_DIR = ./src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

all: chess

chess: $(SRC_FILES)
	$(CC) -o $@ $^

clean:
	rm -f chess