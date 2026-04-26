#include "mandelbrot.h"
#include <fstream>
#include <iostream>
#include <vector>

MandelbrotSet::MandelbrotSet(int width, int height)
    : width(width), height(height), maxIterations(256) {}

int MandelbrotSet::calculateEscapeTime(std::complex<double> c) const {
    std::complex<double> z(0, 0);
    int iterations = 0;
while (std::norm(z) <= 4.0 && iterations < maxIterations) {
    z = z * z + c;
    iterations++;
}
    return iterations;
}

void MandelbrotSet::generate(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) return;

outFile << "P3\n" << width << " " << height << "\n255\n";

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double re = -2.0 + 3.0 * x / width;
            double im = -1.5 + 3.0 * y / height;
            
            int iterations = calculateEscapeTime(std::complex<double>(re, im));
            
if (iterations == maxIterations) {
    outFile << "0 0 0 ";
} else {
    int r = (iterations * 10) % 256;
    int g = (iterations * 3) % 256;
    int b = (iterations * 7) % 256;
    outFile << r << " " << g << " " << b << " ";
}
        }
        outFile << "\n";
    }
    outFile.close();
}
