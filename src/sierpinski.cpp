#include "sierpinski.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

SierpinskiTriangle::SierpinskiTriangle(int width, int height)
    : width(width), height(height) {}

void SierpinskiTriangle::generate(const std::string& filename, int iterations) const {
    std::vector<std::vector<bool>> grid(height, std::vector<bool>(width, false));
    std::srand(std::time(nullptr));

    // Define vertices of the triangle
    struct Point { int x, y; };
    Point vertices[3] = {
        {width / 2, 20},
        {20, height - 20},
        {width - 20, height - 20}
    };

    // Initial random point inside the triangle
    Point current = {width / 2, height / 2};

    // Chaos Game
    for (int i = 0; i < iterations; ++i) {
        int target = std::rand() % 3;
        current.x = (current.x + vertices[target].x) / 2;
        current.y = (current.y + vertices[target].y) / 2;
        
        if (current.x >= 0 && current.x < width && current.y >= 0 && current.y < height) {
            grid[current.y][current.x] = true;
        }
    }

    // Write to PPM file
    std::ofstream outFile(filename);
    if (!outFile) return;

    outFile << "P3\n" << width << " " << height << "\n255\n";

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (grid[y][x]) {
                outFile << "0 200 100 "; // Greenish for points
            } else {
                outFile << "255 255 255 "; // White background
            }
        }
        outFile << "\n";
    }
    outFile.close();
}
