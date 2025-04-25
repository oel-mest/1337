#include "Point.hpp"

Point::Point(void)
{
    Fixed x, y;
}

Point::Point(const float& one, const float& two): x(one), y(two)
{
}

Point::Point(const Point& other): x(other.x), y(other.y)
{
}

Point& Point::operator=(const Point& other)
{
	(void)other;
   return *this;
}

Point::~Point(void) {}

float Point::get_x_value(void) const
{
    return x.toFloat();
}

float Point::get_y_value(void) const
{
    return y.toFloat();
}

Fixed Point::get_x(void) const 
{
    return x;
}

Fixed Point::get_y(void) const
{
    return y;
}

std::ostream &operator<<(std::ostream &o, const Point &obj)
{
	o << "(" << obj.get_x_value() << "," << obj.get_y_value() << ")";
	return (o);
}