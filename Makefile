CC = gcc
SRC_C = $(wildcard ./src/*.c)
SRC_H = $(wildcard ./src/*.h)
OUT = coresh

run:
	$(CC) $(SRC_C) $(SRC_H) -o $(OUT) && ./$(OUT)

debug:
	valgrind ./$(OUT)

clean:
	rm -f $(OUT)