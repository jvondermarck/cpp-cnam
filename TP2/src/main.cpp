#include <iostream>
#include "point.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include <string>  

int main()
{
    std::cout << "Hello World";
    Point A;
    A.x= 2;
    A.y = 3;

    Point B;
    B.x = 2;
    B.y = 6;

    Point C;
    C.x = 5;
    C.y = 3;

    Triangle triangle (A, B, C);
    std::cout << "Base : " << std::__cxx11::to_string(triangle.base()) << std::endl;
    std::cout << "Hauteur : " << std::__cxx11::to_string(triangle.hauteur()) << std::endl;
    std::cout << "Surface : " << std::__cxx11::to_string(triangle.surface()) << std::endl;
}
