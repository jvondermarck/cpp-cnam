#include "rectangle.hpp"

Rectangle::Rectangle (const int _longueur, const int _largueur) : longueur(_longueur), largueur(_largueur) {}

/* ou déclarer ainsi son constructeur (moins optimisé)
Rectangle::Rectangle (const int longueur, const int largueur)
{
    this->longueur = longueur;
    this->largueur = largueur;
}
*/

/**
 * Note pour moi : je mets dans les paramètres le mot const et je passe la référence de l'objet :
 *  - Pour éviter de créer une copie local de mon objet (perte de peformance en +)
 *  - Pour éviter qu'on modifie l'objet je mets le mot const en sécurité
 */
bool Rectangle::estPlusGrandPerimetre(const Rectangle &rectangle) const
{
    return this->getPerimetre() > rectangle.getPerimetre();
}

bool Rectangle::estPlusGrandSurface(const Rectangle &rectangle) const
{
    return this->getSurface() > rectangle.getSurface();
}

//  J'utilise le mot const en dehors des paramètres que dans la fonction pour éviter qu'on fasse des modifications sur les variables
int Rectangle::getPerimetre() const
{ 
    return 2 * (this->longueur + this->largueur); 
}

int Rectangle::getSurface() const
{ 
    return longueur*largueur; 
}