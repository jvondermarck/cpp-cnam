#include "rectangle.hpp"

bool Rectangle::estPlusGrandPerimetre(Rectangle rectangle)
{
    return this->getPerimetre() > rectangle.getPerimetre();
}

bool Rectangle::estPlusPetitSurface(Rectangle rectangle)
{
    return this->getSurface() > rectangle.getSurface();
}

float Rectangle::getPerimetre() 
{ 
    return 2 * (this->longueur + this->largueur); 
}

float Rectangle::getSurface() 
{ 
    return longueur*largueur; 
}