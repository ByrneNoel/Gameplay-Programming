# Compiler and flags
CC := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Werror -g

# Directories
BUILD_DIR := bin
SRC_DIR := ./src
RAYLIB_PATH := C:\mingw64

TARGET := ./${BUILD_DIR}/game.exe
LIBS := -L$(RAYLIB_PATH) -lraylib -lm -lpthread -lgdi32 -luser32 -lkernel32
INCLUDE := -I. -I./include

# Source files
SRC := $(wildcard src/*.cpp)

# Default target to build the project
all: build

# Build target: compile object files and link them to create the executable
build: generate_target
	@echo "Building..."
	${CC} ${CXXFLAGS} -o ${TARGET} ${SRC} ${LIBS} ${INCLUDE}
	@echo "Build complete."
	${TARGET}

generate_target: 
	@echo "Generating build directory"
	mkdir -p "$(BUILD_DIR)"