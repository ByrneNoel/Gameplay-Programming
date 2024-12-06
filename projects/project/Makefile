# Compiler and flags
CXX := ./Raylib/w64devkit/bin/g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Werror -g

# Directories
BUILD_DIR := ./bin
SRC_DIR := ./src
INCLUDE_DIR := ./include
RAYLIB_PATH := ./Raylib/w64devkit/

# Executable target based on the operating system
ifeq ($(OS),Windows_NT)
    TARGET := ${BUILD_DIR}/game.exe
    LIBS := -L$(RAYLIB_PATH)/lib -lraylib -lm -lpthread -lgdi32 -luser32 -lkernel32
else
    TARGET := ${BUILD_DIR}/game.bin
    LIBS := -L$(RAYLIB_PATH)/lib -lraylib -lm -lpthread -ldl -lX11 -lGL -lGLU
endif

# Source files
SRC := ${SRC_DIR}/main.cpp ${SRC_DIR}/Player.cpp ${SRC_DIR}/NPC.cpp ${SRC_DIR}/GameObject.cpp \
    ${SRC_DIR}/AIState.cpp ${SRC_DIR}/InputHandler.cpp ${SRC_DIR}/MagicCommand.cpp ${SRC_DIR}/PlayerMagicState.cpp \
    ${SRC_DIR}/PlayerShieldBlockState.cpp ${SRC_DIR}/PlayerSwordAttackState.cpp ${SRC_DIR}/State.cpp ${SRC_DIR}/ShieldBlockCommand.cpp \
    ${SRC_DIR}/SwordAttackCommand.cpp

# Object files
OBJ := ${BUILD_DIR}/main.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/NPC.o ${BUILD_DIR}/GameObject.o \
    ${BUILD_DIR}/AIState.o ${BUILD_DIR}/InputHandler.o ${BUILD_DIR}/MagicCommand.o ${BUILD_DIR}/PlayerMagicState.o \
    ${BUILD_DIR}/PlayerShieldBlockState.o ${BUILD_DIR}/PlayerSwordAttackState.o ${BUILD_DIR}/State.o ${BUILD_DIR}/ShieldBlockCommand.o \
    ${BUILD_DIR}/SwordAttackCommand.o

# Default target to build the project
all: build

# Build target: compile object files and link them to create the executable
build: ${OBJ}
	@echo "Linking..."
	${CXX} -o ${TARGET} ${OBJ} ${LIBS}
	@echo "Build complete."
	./${TARGET}

# Compile source files into object files
${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp
	@mkdir -p $(BUILD_DIR)
	${CXX} ${CXXFLAGS} -I$(RAYLIB_PATH)/include -I$(INCLUDE_DIR) -c $< -o $@

${BUILD_DIR}/Player.o: ${SRC_DIR}/Player.cpp
	${CXX} ${CXXFLAGS} -I$(RAYLIB_PATH)/include -I$(INCLUDE_DIR) -c $< -o $@

${BUILD_DIR}/NPC.o: ${SRC_DIR}/NPC.cpp
	${CXX} ${CXXFLAGS} -I$(RAYLIB_PATH)/include -I$(INCLUDE_DIR) -c $< -o $@

${BUILD_DIR}/GameObject.o: ${SRC_DIR}/GameObject.cpp
	${CXX} ${CXXFLAGS} -I$(RAYLIB_PATH)/include -I$(INCLUDE_DIR) -c $< -o $@

${BUILD_DIR}/AIState.o: ${SRC_DIR}/AIState.cpp
	${CXX} ${CXXFLAGS} -I$(RAYLIB_PATH)/include -I$(INCLUDE_DIR) -c $< -o $@

${BUILD_DIR}/InputHandler.o: ${SRC_DIR}/InputHandler.cpp
	${CXX} ${CXXFLAGS} -I$(RAYLIB_PATH)/include -I$(INCLUDE_DIR) -c $< -o $@

${BUILD_DIR}/MagicCommand.o: ${SRC_DIR}/MagicCommand.cpp
	${CXX} ${CXXFLAGS} -I$(RAYLIB_PATH)/include -I$(INCLUDE_DIR) -c $< -o $@

${BUILD_DIR}/PlayerMagicState.o: ${SRC_DIR}/PlayerMagicState.cpp
	${CXX} ${CXXFLAGS} -I$(RAYLIB_PATH)/include -I$(INCLUDE_DIR) -c $< -o $@

${BUILD_DIR}/PlayerShieldBlockState.o: ${SRC_DIR}/PlayerShieldBlockState.cpp
	${CXX} ${CXXFLAGS} -I$(RAYLIB_PATH)/include -I$(INCLUDE_DIR) -c $< -o $@

${BUILD_DIR}/PlayerSwordAttackState.o: ${SRC_DIR}/PlayerSwordAttackState.cpp
	${CXX} ${CXXFLAGS} -I$(RAYLIB_PATH)/include -I$(INCLUDE_DIR) -c $< -o $@

${BUILD_DIR}/State.o: ${SRC_DIR}/State.cpp
	${CXX} ${CXXFLAGS} -I$(RAYLIB_PATH)/include -I$(INCLUDE_DIR) -c $< -o $@

${BUILD_DIR}/ShieldBlockCommand.o: ${SRC_DIR}/ShieldBlockCommand.cpp
	${CXX} ${CXXFLAGS} -I$(RAYLIB_PATH)/include -I$(INCLUDE_DIR) -c $< -o $@

${BUILD_DIR}/SwordAttackCommand.o: ${SRC_DIR}/SwordAttackCommand.cpp
	${CXX} ${CXXFLAGS} -I$(RAYLIB_PATH)/include -I$(INCLUDE_DIR) -c $< -o $@

# Clean target: remove the build directory and its contents
.PHONY: clean
clean:
	@echo "Cleaning up..."
	rm -rf ${BUILD_DIR} || true
