# Makefile for C practice inside the Rust project.
# Place this file in the project root (next to Cargo.toml).
#
# Layout:
#   src/*.c that define main()  -> programs, built into bin/<name>
#   src/*.c without main()      -> library files, linked into every program
#
# Usage:
#   make                build every program into bin/
#   make build          build only bin/main
#   make build NAME=foo build only bin/foo (from src/foo.c)
#   make run            build and run bin/main
#   make run NAME=foo   build and run bin/foo (from src/foo.c)
#   make clean          remove built files only (never touches src)

CC      := gcc
CFLAGS  := -std=gnu23 -Wall -Wextra -g3 -fsanitize=address,undefined
NAME    ?= main

SRC_DIR := src
BIN_DIR := bin
OBJ_DIR := obj

SRCS      := $(wildcard $(SRC_DIR)/*.c)
# A file is a program if it contains a line like "int main(" or "void main(".
# The pattern lives in a variable because make would count its "(" as unbalanced inside $(shell ...).
MAIN_RE   := ^[[:space:]]*(int|void)[[:space:]]+main[[:space:]]*\(
MAIN_SRCS := $(if $(SRCS),$(shell grep -l -E '$(MAIN_RE)' $(SRCS)))
LIB_SRCS  := $(filter-out $(MAIN_SRCS),$(SRCS))

LIB_OBJS  := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(LIB_SRCS))
BINS      := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%,$(MAIN_SRCS))
DEPS      := $(wildcard $(OBJ_DIR)/*.d)

.PHONY: all build run clean
.SECONDARY:

all: $(BINS)

build: $(BIN_DIR)/$(NAME)

# Link: the program's own object file plus all library objects.
$(BIN_DIR)/%: $(OBJ_DIR)/%.o $(LIB_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Compile: -MMD -MP tracks header changes, so editing a .h rebuilds what uses it.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

run: build
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo ""
	@./$(BIN_DIR)/$(NAME)
#	@echo ""
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

clean:
	rm -rf $(BINS) $(OBJ_DIR)

-include $(DEPS)