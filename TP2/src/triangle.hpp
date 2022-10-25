#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include<cmath>
#include "point.hpp"

class Triangle {
    public:
        /**
         * @brief Construire un triangle avec 3 points différents
         * 
         * @param point_a : Point coordinate
         * @param point_b : Point coordinate
         * @param point_c : Point coordinate
         */
        Triangle(Point _point_A, Point _point_B, Point _point_C);

        /**
         * @brief Détruire l'objet Triangle
         */
        ~Triangle() = default;

        float distanceDeuxPoints(const Point &point_A, const Point &point_B) const;

        /**
         * @brief La base du triangle, la plus grande valeur
         * 
         * @return float
         */
        float base();
        
        /**
         * @brief La hauteur du triangle
         * 
         * @return float 
         */
        float hauteur();

        /**
         * @brief La surface du triangle
         * 
         * @return float 
         */
        float surface();

        /**
         * @brief La longueur du triangle
         * 
         * @return float 
         */
        float longueur();

        /**
         * @brief Si le triangle est isocele ou non
         * 
         * @return true 
         * @return false 
         */
        bool estIsocele();

        /**
         * @brief Si le triangle est rectangle ou non
         * 
         * @return true 
         * @return false 
         */
        bool estRectangle();

        /**
         * @brief Si le triangle est equilatéral ou non
         * 
         * @return true 
         * @return false 
         */
        bool estEquilateral();

        /**
         * @brief Set the Point A object
         * 
         * @param a 
         */
        inline void setPointA(Point &point_a) { this->point_A = point_a; }

        /**
         * @brief Get the Point A object
         * 
         * @return Point 
         */
        inline Point getPointA() const { return this->point_A; }

        /**
         * @brief Set the Point B object
         * 
         * @param b 
         */
        inline void setPointB(Point &point_B) { this->point_B = point_B; }

        /**
         * @brief Get the Point B object
         * 
         * @return Point 
         */
        inline Point getPointB() const { return this->point_B; }
        
        /**
         * @brief Set the Point C object
         * 
         * @param c 
         */
        inline void setPointC(Point &point_C) { this->point_C = point_C; }

        /**
         * @brief Get the Point C object
         * 
         * @return Point 
         */
        inline Point getPointC() const { return this->point_C; }
    private:
        Point point_A;
        Point point_B;
        Point point_C;
};

#endif 