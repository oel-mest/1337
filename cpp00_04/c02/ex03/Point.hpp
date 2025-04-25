#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point(void);
        Point(const float& one, const float& two);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point(void);

        float get_x_value(void) const;
        float get_y_value(void) const;
        Fixed get_x(void) const;
        Fixed get_y(void) const;
};

std::ostream &operator<<(std::ostream &o, const Point &obj);

#endif // POINT_HPP