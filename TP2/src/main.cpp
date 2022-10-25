#include <iostream>
#include "point.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include <string>  

void afficher_triangle(Triangle triangle)
{
    std::cout << "Triangle : " << std::endl;
    std::cout << " - Base : " << triangle.base() << std::endl;
    std::cout << " - Hauteur : " << triangle.hauteur() << std::endl;
    std::cout << " - Surface : " << triangle.surface() << std::endl;
    std::cout << " - Longueur : " << triangle.longueur() << std::endl;
    std::cout << " - Est rectangle ? : " << triangle.estRectangle() << std::endl;
    std::cout << " - Est isocèle ? : " << triangle.estIsocele() << std::endl;
    std::cout << " - Est équilérateral ? : " << triangle.estEquilateral() << std::endl;
}

int main()
{
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
    afficher_triangle(triangle);
    
    A.x = 0;
    A.y = 0;
    B.x = 8;
    B.y = 0;
    C.x = 4;
    C.y = 6;

    Triangle triangle2 (A, B, C);
    afficher_triangle(triangle2);    

    Point d;
    d.x = 1.5;
    d.y = 4;
    Point e;
    e.x = 1.5;
    e.y = 2;
    Point f;
    f.x = 1.5;
    f.y = 6;
    Triangle triangle3 = Triangle(d,e,f);
    afficher_triangle(triangle3); 
}
