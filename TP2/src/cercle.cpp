#include "cercle.hpp"

float Cercle::distance_deux_points(const Point &point)
{
    return std::sqrt((std::pow(point.x - this->point_centre.x, 2)) + (std::pow(point.y - this->point_centre.y, 2)));
}

bool Cercle::estSurLeCercle(const Point &point) 
{
    return distance_deux_points(point) == this->diametre;
}

bool Cercle::estDansLeCercle(const Point &point) 
{
    return distance_deux_points(point) < this->diametre;
}

float Cercle::getPerimetre() const
{
    return M_PI*this->diametre;
}

float Cercle::getSurface() const
{
    return M_PI*std::pow(this->diametre/2, 2);
}