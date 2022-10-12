#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include "point.hpp"

class Cercle {
    public:
        /**
         * @brief Construct a new Cercle object
         * 
         * @param a : Point coordinate
         * @param b : Point coordinate
         * @param c : Point coordinate
         */
        Cercle(Point a, Point b, Point c)
        {
            A = a;
            B = b;
            C = c;
        }

        /**
         * @brief La base du triangle, la plus grande valeur
         * 
         * @return float
         */
        float base();



        /**
         * @brief Set the Point A object
         * 
         * @param a 
         */
        inline void setPointA(Point a) { this->A = a; }

        /**
         * @brief Get the Point A object
         * 
         * @return Point 
         */
        inline Point getPointA() const { return this->A; }

        /**
         * @brief Set the Point B object
         * 
         * @param b 
         */
        inline void setPointB(Point b) { this->B = b; }

        /**
         * @brief Get the Point B object
         * 
         * @return Point 
         */
        inline Point getPointB() const { return this->B; }
        
        /**
         * @brief Set the Point C object
         * 
         * @param c 
         */
        inline void setPointC(Point c) { this->C = c; }

        /**
         * @brief Get the Point C object
         * 
         * @return Point 
         */
        inline Point getPointC() const { return this->C; }
    private:
        Point A, B, C;
};

#endif 