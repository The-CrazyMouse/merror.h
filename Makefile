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
# Object files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
# Header files
HEADERS := $(wildcard $(INCLUDE_DIR)/*.h)
# Test source files
TEST_SRCS := $(wildcard $(TESTS_DIR)/*.c)
# Test executables
TESTS := $(patsubst $(TESTS_DIR)/%.c, $(BIN_DIR)/%, $(TEST_SRCS))

# Targets
STATIC_LIB := $(LIB_DIR)/static/merror.a
DYNAMIC_LIB := $(LIB_DIR)/dynamic/merror.so

# Main target
.PHONY: all
all: $(STATIC_LIB) $(DYNAMIC_LIB)
	@echo "Compiling static and dynamic libraries"

# Static library target
$(STATIC_LIB): $(OBJ_FILES) | $(LIB_DIR)/static
	ar rcs $@ $^

# Dynamic library target
$(DYNAMIC_LIB): $(OBJ_FILES) | $(LIB_DIR)/dynamic
	$(CC) $(CFLAGS) -shared -o $@ $^
	
# Object files target
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -fPIC -o $@ $<

# Test executables
$(BIN_DIR)/%: $(TESTS_DIR)/%.c $(STATIC_LIB)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -L$(LIB_DIR)/static -lmerror -o $@s

# Create directories
$(OBJ_DIR) $(LIB_DIR)/static $(LIB_DIR)/dynamic:
	# @echo "Creating directories"
	mkdir -p $@

# Clean
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR) error.log

# Phony target for running tests
.PHONY: test
test: $(TESTS)
	@$(foreach test, $(TESTS), echo "Running $(test)"; $(test);)



