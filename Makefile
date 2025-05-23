CC = gcc
SRC_C = $(wildcard ./src/*.c)
OUT = ./out
BIN = coresh
TARGET = $(OUT)/$(BIN)

all: $(TARGET)

$(TARGET): $(SRC_C)
	mkdir -p $(OUT)
	$(CC) $(SRC_C) -o $(TARGET)

run: $(TARGET)
	@echo "Running..."
	@$(TARGET)

debug: $(TARGET)
	valgrind $(TARGET)

clean:
	rm -f $(TARGET)