#include "julia.h"
#include <cmath>

JuliaGenerator::JuliaGenerator(int width, int height, std::complex<double> c)
: width(width), height(height), c(c), maxIterations(256) {}

int JuliaGenerator::iterate(std::complex<double> z) const {
    int iterations = 0;
while (std::norm(z) < 4.0 && iterations < maxIterations) {
    z = z * z + c;
    iterations++;
}
return iterations;
}

Color JuliaGenerator::getPixelColor(int x, int y) const {
    double re = -2.0 + 4.0 * x / width;
    double im = -2.0 + 4.0 * y / height;
    std::complex<double> z(re, im);

    int iterations = iterate(z);

if (iterations == maxIterations) {
    return {0, 0, 0}; 
}

    int r = (iterations * 9) % 256;
    int g = (iterations * 5) % 256;
    int b = (iterations * 11) % 256;

return {r, g, b};
}
