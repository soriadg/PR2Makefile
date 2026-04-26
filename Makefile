CXX = g++
CXXFLAGS = -O3 -Wall -Wextra -Iinclude -std=c++11

TARGET = pattern_gen
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
OUTPUT_DIR = output

SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/mandelbrot.cpp $(SRC_DIR)/sierpinski.cpp
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/mandelbrot.o $(OBJ_DIR)/sierpinski.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

run_mandelbrot: $(TARGET) | $(OUTPUT_DIR)
	./$(TARGET) mandelbrot

run_sierpinski: $(TARGET) | $(OUTPUT_DIR)
	./$(TARGET) sierpinski

clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(OUTPUT_DIR)/*.ppm

.PHONY: all run_mandelbrot run_sierpinski clean
