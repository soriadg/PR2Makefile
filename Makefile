# Compiler and flags
CXX = g++
CXXFLAGS = -O3 -Wall -Wextra -Iinclude -std=c++11

# Target and directories
TARGET = pattern_gen
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
OUTPUT_DIR = output

# Source and object files
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/mandelbrot.cpp $(SRC_DIR)/sierpinski.cpp
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/mandelbrot.o $(OBJ_DIR)/sierpinski.o

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Create the object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create the output directory
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Run targets
run_mandelbrot: $(TARGET) | $(OUTPUT_DIR)
	./$(TARGET) mandelbrot

run_sierpinski: $(TARGET) | $(OUTPUT_DIR)
	./$(TARGET) sierpinski

# Clean up build artifacts
clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(OUTPUT_DIR)/*.ppm

.PHONY: all run_mandelbrot run_sierpinski clean
