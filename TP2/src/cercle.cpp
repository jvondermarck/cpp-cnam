#include "cercle.hpp"

Cercle::Cercle(Point _point, int _diametre): point_centre(_point), diametre(_diametre) {}

float Cercle::distanceDeuxPoints(const Point &point)  const
{
    return std::sqrt((std::pow(point.x - this->point_centre.x, 2)) + (std::pow(point.y - this->point_centre.y, 2)));
}

bool Cercle::estSurLeCercle(const Point &point) const
{
    return distanceDeuxPoints(point) == this->diametre;
}

bool Cercle::estDansLeCercle(const Point &point) const
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

void Cercle::afficher(Point &dansCercle, Point &surCercle) const
{
    std::cout << "Cercle : " << std::endl;
    std::cout << " - Périmètre : " << this->getPerimetre() << std::endl;
    std::cout << " - Surface : " << this->getSurface() << std::endl;
    std::cout << " - Point xCentre : " << this->getCentre().x << " - yCentre : " << this->getCentre().y << std::endl;
    std::cout << " - Est dans cercle ? : " << this->estDansLeCercle(dansCercle) << std::endl;
    std::cout << " - Est sur le cercle ? : " << this->estSurLeCercle(surCercle) << std::endl;
}