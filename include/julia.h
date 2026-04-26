#ifndef JULIA_H
#define JULIA_H

#include <complex>
#include <vector>

struct Color {
int r, g, b;
};

class JuliaGenerator {
public:
JuliaGenerator(int width, int height, std::complex<double> c);

Color getPixelColor(int x, int y) const;

int getWidth() const { return width; }
int getHeight() const { return height; }

private:
int width, height;
std::complex<double> c;
int maxIterations;

int iterate(std::complex<double> z) const;
};

#endif
