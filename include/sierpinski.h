#ifndef SIERPINSKI_H
#define SIERPINSKI_H

#include <string>
#include <vector>

class SierpinskiTriangle {
public:
    SierpinskiTriangle(int width, int height);
    void generate(const std::string& filename, int iterations) const;

private:
    int width, height;
};

#endif // SIERPINSKI_H
