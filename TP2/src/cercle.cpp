#include "cercle.hpp"

Cercle::Cercle(Point _point, int _diametre): point_centre(_point), diametre(_diametre) {}

float Cercle::distanceDeuxPoints(const Point &point)
{
    return std::sqrt((std::pow(point.x - this->point_centre.x, 2)) + (std::pow(point.y - this->point_centre.y, 2)));
}

bool Cercle::estSurLeCercle(const Point &point) 
{
    return distanceDeuxPoints(point) == this->diametre;
}

bool Cercle::estDansLeCercle(const Point &point) 
{
    return distanceDeuxPoints(point) < this->diametre;
}

float Cercle::getPerimetre() const
{
    return M_PI*this->diametre;
}

float Cercle::getSurface() const
{
    return M_PI*std::pow(this->diametre/2, 2);
}