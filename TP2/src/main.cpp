#include "point.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "cercle.hpp"

int main()
{
    // Rectangle
    Rectangle rectangle (10, 5);
    Rectangle grandPerimetre (5, 5);
    Rectangle grandSurface (6, 6);
    rectangle.afficher(grandPerimetre, grandSurface);

    // Cercle
    Point pointCercle = Point {3,3};
    Point dansCercle = Point{2,2};
    Point surCercle = Point {3,3};
    Cercle cercle (pointCercle, 6);
    cercle.afficher(dansCercle, surCercle);

    // Triangle 
    Point A = Point {0,0};
    Point B = Point {0,3};
    Point C = Point {4,0};
    Triangle triangle (A, B, C);
    triangle.afficher();
}
