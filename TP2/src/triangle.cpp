#include "triangle.hpp"

Triangle::Triangle(Point _point_A, Point _point_B, Point _point_C): point_A(_point_A), point_B(_point_B), point_C(_point_C) {}

float Triangle::distanceDeuxPoints(const Point &point_A, const Point &point_B) const
{
    return std::sqrt((std::pow(point_B.x - point_A.x, 2)) + (std::pow(point_B.y - point_A.y, 2)));
}

float Triangle::base() const
{
    float AB = distanceDeuxPoints(this->point_A, this->point_B);
    float AC = distanceDeuxPoints(this->point_A, this->point_C);
    float BC = distanceDeuxPoints(this->point_B, this->point_C);
    float plusGrandValeur = AB;

    if(plusGrandValeur < AC && AC > BC) plusGrandValeur = AC;
    if(plusGrandValeur < BC) plusGrandValeur = BC;
    return plusGrandValeur;
}

float Triangle::hauteur() const
{
    return 2*(this->surface() / this->base());
}

float Triangle::surface() const
{
    float semi_perimetre = this->longueur()/2;
    return std::sqrt(semi_perimetre * (semi_perimetre-distanceDeuxPoints(this->point_A, this->point_B))*(semi_perimetre-distanceDeuxPoints(this->point_A, this->point_C))*(semi_perimetre-distanceDeuxPoints(this->point_B, this->point_C)));
}

float Triangle::longueur() const
{
    return distanceDeuxPoints(this->point_A, this->point_B) + distanceDeuxPoints(this->point_A, this->point_C) + distanceDeuxPoints(this->point_B, this->point_C);
}

bool Triangle::estIsocele() const
{
    float AB = distanceDeuxPoints(this->point_A, this->point_B);
    float AC = distanceDeuxPoints(this->point_A, this->point_C);
    float BC = distanceDeuxPoints(this->point_B, this->point_C);

    return ((AB == BC) || (AB == AC) || (BC == BC));
}

bool Triangle::estRectangle() const
{
    float AB = distanceDeuxPoints(this->point_A, this->point_B);
    float AC = distanceDeuxPoints(this->point_A, this->point_C);
    float BC = distanceDeuxPoints(this->point_B, this->point_C);
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

bool Triangle::estEquilateral() const
{
    float AB = distanceDeuxPoints(this->point_A, this->point_B);
    float AC = distanceDeuxPoints(this->point_A, this->point_C);
    float BC = distanceDeuxPoints(this->point_B, this->point_C);

    return (AB == BC) && (AB == AC) && (BC == AC);
}

void Triangle::afficher() const
{
    std::cout << "Triangle : " << std::endl;
    std::cout << " - Base : " << this->base() << std::endl;
    std::cout << " - Hauteur : " << this->hauteur() << std::endl;
    std::cout << " - Surface : " << this->surface() << std::endl;
    std::cout << " - Longueur : " << this->longueur() << std::endl;
    std::cout << " - Point Ax : " << this->getPointA().x << " - Ay : " << this->getPointA().y << std::endl;
    std::cout << " - Point Bx : " << this->getPointB().x << " - By : " << this->getPointB().y << std::endl;
    std::cout << " - Point Cy : " << this->getPointC().x << " - Cy : " << this->getPointC().y << std::endl;
    std::cout << " - Est rectangle ? : " << this->estRectangle() << std::endl;
    std::cout << " - Est isocèle ? : " << this->estIsocele() << std::endl;
    std::cout << " - Est équilérateral ? : " << this->estEquilateral() << std::endl;
}

// std::cout << " - AB : " << std::__cxx11::to_string(AB) << std::endl;
// std::cout << " - AC : " << std::__cxx11::to_string(AC) << std::endl;
// std::cout << " - BC : " << std::__cxx11::to_string(BC) << std::endl;