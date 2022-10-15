#include <iostream>
#include "point.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include <string>  

int main()
{
    std::cout << "Triangle : " << std::endl;
    Point A;
    A.x = 0;
    A.y = 0;

    Point B;
    B.x = 0;
    B.y = 3;

    Point C;
    C.x = 4;
    C.y = 0;

    Triangle triangle (A, B, C);
    std::cout << " - Base : " << std::__cxx11::to_string(triangle.base()) << std::endl;
    std::cout << " - Hauteur : " << std::__cxx11::to_string(triangle.hauteur()) << std::endl;
    std::cout << " - Surface : " << std::__cxx11::to_string(triangle.surface()) << std::endl;
    std::cout << " - Longueur : " << std::__cxx11::to_string(triangle.longueur()) << std::endl;
    std::cout << " - Est rectangle ? : " << triangle.estRectangle() << std::endl;
}
