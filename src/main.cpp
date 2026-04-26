#include <iostream>
#include <string>
#include "mandelbrot.h"
#include "sierpinski.h"

int main(int argc, char* argv[]) {
if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <pattern>\n";
    std::cout << "Available patterns: mandelbrot, sierpinski\n";
    return 1;
}

    std::string pattern = argv[1];
    int width = 800;
    int height = 800;

if (pattern == "mandelbrot") {
    std::cout << "Generating Mandelbrot Set...\n";
    MandelbrotSet mandel(width, height);
    mandel.generate("output/mandelbrot.ppm");
    std::cout << "Created output/mandelbrot.ppm\n";
    } else if (pattern == "sierpinski") {
        std::cout << "Generating Sierpinski Triangle via Chaos Game...\n";
        SierpinskiTriangle sierpinski(width, height);
        sierpinski.generate("output/sierpinski.ppm", 1000000); 
        std::cout << "Created output/sierpinski.ppm\n";
} else {
    std::cerr << "Unknown pattern: " << pattern << std::endl;
    return 1;
}

    return 0;
}
