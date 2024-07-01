# Compiler
CC := gcc

# Flags
CFLAGS := -Wall -Wextra -Werror -pedantic -Iinclude -std=c99

# Directories
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
LIB_DIR := lib
BIN_DIR := bin
TEST_DIR := test

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
HEADERS := $(wildcard $(INC_DIR)/*.h)
# Test source file
TEST_SRC := $(TEST_DIR)/main.c
# Test executable
TEST_EXEC := $(BIN_DIR)/test_merror

# Targets
STATIC_LIB := $(LIB_DIR)/static/merror.a
DYNAMIC_LIB := $(LIB_DIR)/dynamic/merror.so

# All: this will compile the static and dynamic libraries
.PHONY: all
all: $(STATIC_LIB) $(DYNAMIC_LIB)
	@echo "Compiling static and dynamic libraries"

# Static library
$(STATIC_LIB): $(OBJ_FILES) | $(LIB_DIR)/static
	@echo "Creating static library"
	@ar rcs $@ $^

# Dynamic library
$(DYNAMIC_LIB): $(OBJ_FILES) | $(LIB_DIR)/dynamic
	@echo "Creating dynamic library"
	@$(CC) $(CFLAGS) -shared -o $@ $^
	
# Object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling object files from $<"
	@$(CC) $(CFLAGS) -c -fPIC -o $@ $<

# Test executable
$(TEST_EXEC): $(TEST_SRC) $(SRC_FILES) | $(BIN_DIR)
	@echo "Creating test executable"
	@$(CC) $(CFLAGS) -o $@ $(TEST_SRC) $(SRC_FILES)

# Create directories
$(OBJ_DIR) $(LIB_DIR)/static $(LIB_DIR)/dynamic $(BIN_DIR):
	@echo "Creating directory $@"
	@mkdir -p $@

# Phony target for running tests
.PHONY: test
test: $(TEST_EXEC)
	@echo "Running tests"
	@echo "--------------------------------"
	@$(TEST_EXEC)

# Clean
.PHONY: clean
clean:
	@echo "Cleaning up"
	@rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR) error.log
