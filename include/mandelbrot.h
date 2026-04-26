#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <complex>
#include <string>

class MandelbrotSet {
public:
MandelbrotSet(int width, int height);
void generate(const std::string& filename) const;

private:
int width, height;
int maxIterations;
int calculateEscapeTime(std::complex<double> c) const;
};

#endif
