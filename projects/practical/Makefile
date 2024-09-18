CXX             := g++
MSG_START       := "Build Started"
MSG_END         := "Build Complete"
MSG_CLEAN       := "Cleaning up"
BUILD_DIR       := ./bin
SRC_DIR         := ./src
INC_DIR         := ./include
TARGET          := ${BUILD_DIR}/sampleapp.bin
SRC             := ${SRC_DIR}/main.cpp ${SRC_DIR}/sample_function.cpp
CXXFLAGS        := -Wall
DEBUG           := 1

ifeq ($(DEBUG), 1)
        CXXFLAGS += -g
else
        CXXFLAGS += -O2
endif

all: build

build:	$(BUILD_DIR)

	@echo ${MSG_START}
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) -I${INC_DIR}
	@echo "\033[0;32m${MSG_END}\033[0m"
	./${TARGET} # Auto runs program

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) # Create build directory if it doesn't exist

clean:
	@echo ${MSG_CLEAN}
	rm -rf ${BUILD_DIR}
