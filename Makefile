CC = gcc
SRC_C = $(wildcard ./src/*.c)
SRC_H = $(wildcard ./src/*.h)
OUT = ./out
BIN = coresh

build:
	mkdir -p $(OUT) && $(CC) $(SRC_C) $(SRC_H) -o $(OUT)/$(BIN)

run:
	 $(OUT)/$(BIN)

debug:
	valgrind ./$(OUT)

clean:
	rm -f $(OUT)