#include <iostream>
#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);
    Point p(5, 5);
    Point q(10, 0);

    std::cout << std::boolalpha;
    std::cout << "p inside triangle? " << bsp(a, b, c, p) << std::endl;
    std::cout << "q inside triangle? " << bsp(a, b, c, q) << std::endl;
}
