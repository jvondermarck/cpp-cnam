#include "triangle.hpp"

float Triangle::distance_deux_points(const Point &pointA, const Point &pointB)
{
    return std::sqrt((std::pow(pointB.x - pointA.x, 2)) + (std::pow(pointB.y - pointA.y, 2)));
}

float Triangle::base() 
{
    float AB = distance_deux_points(this->point_A, this->point_B);
    float AC = distance_deux_points(this->point_A, this->point_C);
    float BC = distance_deux_points(this->point_B, this->point_C);
    float plusGrandValeur = AB;

    if(plusGrandValeur < AC && AC > BC) plusGrandValeur = AC;
    if(plusGrandValeur < BC) plusGrandValeur = BC;
    return plusGrandValeur;
}

float Triangle::hauteur()
{
    return 2*(this->surface() / this->base());
}

float Triangle::surface()
{
    float semi_perimetre = this->longueur()/2;
    return std::sqrt(semi_perimetre * (semi_perimetre-distance_deux_points(this->point_A, this->point_B))*(semi_perimetre-distance_deux_points(this->point_A, this->point_C))*(semi_perimetre-distance_deux_points(this->point_B, this->point_C)));
}

float Triangle::longueur()
{
    return distance_deux_points(this->point_A, this->point_B) + distance_deux_points(this->point_A, this->point_C) + distance_deux_points(this->point_B, this->point_C);
}

bool Triangle::estIsocele()
{
    return (distance_deux_points(this->point_A, this->point_B) == distance_deux_points(this->point_A, this->point_C)) || 
        (distance_deux_points(this->point_A, this->point_B) == distance_deux_points(this->point_B, this->point_C)) ||
        (distance_deux_points(this->point_A, this->point_C) == distance_deux_points(this->point_B, this->point_C));
}

bool Triangle::estRectangle()
{
    float AB = distance_deux_points(this->point_A, this->point_B);
    float AC = distance_deux_points(this->point_A, this->point_C);
    float BC = distance_deux_points(this->point_B, this->point_C);
    float plusGrandValeur = AB;
    
    float addition = addition = std::pow(AC, 2) + std::pow(BC, 2);;
    if(plusGrandValeur < AC && AC > BC){
        addition = std::pow(AB, 2) + std::pow(BC, 2);
        plusGrandValeur = AC;
    } else if(plusGrandValeur < BC) {
        addition = std::pow(AB, 2) + std::pow(AC, 2);
        plusGrandValeur = BC;
    }

    return std::pow(plusGrandValeur, 2) == addition;
}

bool Triangle::estEquilateral()
{
    return (distance_deux_points(this->point_A, this->point_B) == distance_deux_points(this->point_A, this->point_C)) && 
        (distance_deux_points(this->point_A, this->point_C) == distance_deux_points(this->point_B, this->point_C));
}