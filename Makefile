# Makefile for C practice inside the Rust project.
# Place this file in the project root (next to Cargo.toml).
#
# Usage:
#   make                build every src/*.c into bin/
#   make build          build only bin/main
#   make build NAME=foo build only bin/foo (from src/foo.c)
#   make run            build and run bin/main
#   make run NAME=foo   build and run bin/foo (from src/foo.c)
#   make clean          remove built binaries only (never touches src)

CC      := gcc
CFLAGS  := -std=gnu23 -Wall -Wextra -g3 -fsanitize=address,undefined
NAME    ?= main

SRC_DIR := src
BIN_DIR := bin

SRCS := $(wildcard $(SRC_DIR)/*.c)
BINS := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%,$(SRCS))

.PHONY: all build run clean

all: $(BINS)

build: $(BIN_DIR)/$(NAME)

$(BIN_DIR)/%: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR):
	mkdir -p $@

run: build
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo ""
	@./$(BIN_DIR)/$(NAME)
#	@echo ""
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

clean:
	rm -f $(BINS)

