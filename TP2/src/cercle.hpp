#ifndef CERCLE_HPP
#define CERCLE_HPP

#include<cmath>
#include "point.hpp"
#include <iostream>

/**
 * @brief Créer un Cercle
 */
class Cercle {
    public:
        /**
         * @brief Constructeur d'un cercle
         * 
         * @param point : le point
         * @param diametre : le diamètre du cercle
         */
        Cercle(Point _point, int _diametre);

        /**
         * @brief Détruire l'objet Cercle
         */
         ~Cercle() = default;

        /**
         * @brief Retourne la distance entre deux points
         * 
         * @param point : le Point en référence à prendre pour évaluer la distance
         * @return float 
         */
        float distanceDeuxPoints(const Point &point) const;

        /**
         * @brief Savoir si un point est sur le cercle
         * 
         * @param point : le Point
         * @return true : si c'est sur le cercle
         * @return false : si cést pas sur le cercle
         */
        bool estSurLeCercle(const Point &point) const;

        /**
         * @brief Savoir si un point est à l'intérieur du cercle
         * 
         * @param point : le Point
         * @return true : si c'est à l'intérieur le cercle
         * @return false : si c'est pas à l'intérieur le cercle
         */
        bool estDansLeCercle(const Point &point) const;

        /**
         * @brief Get the Perimetre of the Cercle
         * 
         * @return float 
         */
        float getPerimetre() const;

        /**
         * @brief Get the Surface of the Cercle
         * 
         * @return float 
         */
        float getSurface() const;

        /**
         * @brief Set the Centre object
         * 
         * @param point l'Objet
         */
        inline void setCentre(const Point &point) { this->point_centre = point; }

        /**
         * @brief Get the Centre object
         * 
         * @return Point reference
         */
        inline Point getCentre() const { return this->point_centre; }

        /**
         * @brief Set the Diametre object
         * 
         * @param diametre 
         */
        inline void setDiametre(int diametre) { this->diametre = diametre; }
        
        /**
         * @brief Get the Diametre object
         * 
         * @return int 
         */
        inline int getDiametre() const { return this->diametre; }

        /**
         * @brief Affiche toutes les informations du cercle
         * @param dansCercle : objet Point pour vérifier si ce point est présent dans le cercle
         * @param surCercle : objet Point pour vérifier si ce point est présent sur le cercle
         */
        void afficher(Point &dansCercle, Point &surCercle) const;
    private:
        /**
         * @brief Le point du cercle au mileu
         */
        Point point_centre;

        /**
         * @brief Le diametre du cercle
         */
        int diametre;
};

#endif 