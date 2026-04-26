#ifndef JULIA_H
#define JULIA_H

#include <complex>
#include <vector>

/**
 * @struct Color
 * @brief Simple RGB color representation.
 */
struct Color {
    int r, g, b;
};

/**
 * @class JuliaGenerator
 * @brief Handles calculation of the Julia set fractal.
 */
class JuliaGenerator {
public:
    /**
     * @brief Constructor for the JuliaGenerator.
     * @param width The width of the image.
     * @param height The height of the image.
     * @param c The complex constant for the Julia set.
     */
    JuliaGenerator(int width, int height, std::complex<double> c);

    /**
     * @brief Calculates the color of a pixel at coordinates (x, y).
     * @param x The horizontal coordinate (0 to width-1).
     * @param y The vertical coordinate (0 to height-1).
     * @return The Color for the pixel.
     */
    Color getPixelColor(int x, int y) const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    int width, height;
    std::complex<double> c;
    int maxIterations;

    /**
     * @brief Iterates the formula z = z^2 + c.
     * @param z The initial complex number.
     * @return The number of iterations before escape.
     */
    int iterate(std::complex<double> z) const;
};

#endif // JULIA_H
