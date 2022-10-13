#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "point.hpp"

class Rectangle{
    public:
        /**
         * @brief Créer un rectangle
         * 
         * @param longueur longueur d'un rectangle
         * @param largueur largueur d'un rectangle
         */
        Rectangle (const int longueur, const int largueur)
        {
            this->longueur = longueur;
            this->largueur = largueur;
        }

        /**
         * @brief renvoie true si l’objet possède un plus grand périmètre  que  le  rectangle passé en paramètre
         * 
         * @param Rectangle un objet rectangle
         * @return true : périmètre objet > périmètre du rectangle en paramètre
         * @return false : périmètre objet < périmètre du rectangle en paramètre
         */
        bool estPlusGrandPerimetre(const Rectangle &rectangle);

        /**
         * @brief renvoie true si l’objet possède une plus grande surface que le rectangle passé en paramètre
         * 
         * @param Rectangle un objet rectangle
         * @return true : surface objet > surface du rectangle en paramètre
         * @return false : surface objet < surface du rectangle en paramètre
         */
        bool estPlusPetitSurface(const Rectangle &rectangle);

        /**
         * @brief Obtenir le périmètre du Rectangle
         * 
         * @return int le périmetre
         */
        inline float getPerimetre() const;

        /**
         * @brief Obtenir la surface du Rectangle
         * 
         * @return int la surface
         */
        inline float getSurface() const;

        /**
         * @brief Mettre la longueur du rectangle
         * 
         * @param longueur
         */
        inline void setLongueur(int longueur) { this->longueur = longueur; }

        /**
         * @brief Obtenir la longueur du rectangle
         * 
         * @return int la longueur du rectangle
         */
        inline int getLongueur() const { return this->longueur; }
        
        /**
         * @brief Mettre la largueur du rectangle
         * 
         * @param largueur
         */
        inline void setLargueur(int largueur) { this->longueur = largueur; }

        /**
         * @brief Obtenir la largueur du rectangle
         * 
         * @return int la largueur du rectangle
         */
        inline int getLargueur() const { return this->largueur; }
        
        /**
         * @brief Mettre l'objet Point du rectangle
         * 
         * @param point ble Point
         */
        inline void setPoint(Point point) { this->point = point; }

        /**
         * @brief Obtenir le Point du rectangle
         * 
         * @return Point l'objet Point
         */
        inline Point getPoint() const { return this->point;}

    private:
        /**
         * @brief La longueur du rectangle
         */
        int longueur;

        /**
         * @brief La largueur du rectangle
         */
        int largueur;

        /**
         * @brief Le Point gauche supérieur du rectangle
         */
        Point point;
};

#endif 