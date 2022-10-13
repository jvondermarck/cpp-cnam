#include "triangle.hpp"

float Triangle::distance_deux_points(const Point &pointA, const Point &pointB)
{
    return std::sqrt((std::pow(pointB.x - pointA.x, 2)) + (std::pow(pointB.y - pointA.y, 2)));
}

float Triangle::base() 
{
    float AB = distance_deux_points(this->A, this->B);
    float AC = distance_deux_points(this->A, this->C);
    float BC = distance_deux_points(this->B, this->C);
    float plusGrandValeur = AB;

    if(plusGrandValeur < AC) plusGrandValeur = AC;
    if(plusGrandValeur < BC) plusGrandValeur = BC;
    return plusGrandValeur;
}

float Triangle::hauteur()
{
    return 2*(this->surface() / this->base());
}

float Triangle::surface()
{
    float s = (distance_deux_points(this->A, this->B) + distance_deux_points(this->A, this->C) + distance_deux_points(this->B, this->C))/2;
    return std::sqrt(s * (s-distance_deux_points(this->A, this->B))*(s-distance_deux_points(this->A, this->C))*(s-distance_deux_points(this->B, this->C)));
}

float Triangle::longueur()
{
    return 0;
}

bool Triangle::estIsocele()
{
    return 0;
}
bool Triangle::estRectangle()
{
    return 0;
}

bool Triangle::estEquilateral()
{
    return 0;
}