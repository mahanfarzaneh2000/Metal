CC= clang
CFLAGS= -Wall -Wextra -ggdb

SRC_DIR= src
SRC_FILES= -I./$(SRC_DIR) src/*.c
BUILD_DIR= build

.PHONY: all executable clean always

executable: always
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/metal $(SRC_FILES)

always:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*
