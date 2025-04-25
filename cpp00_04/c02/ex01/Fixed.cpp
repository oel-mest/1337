#include "Fixed.hpp"

Fixed::Fixed(void): _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other) {
        _value = other._value;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

std::ostream &operator<<(std::ostream &o, const Fixed &obj) {
	o << obj.toFloat();
	return (o);
}


Fixed::~Fixed(void) {
    std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called" << std::endl;
    _value = val << _fractionalBits;
}

Fixed::Fixed(const float val)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(val * (1 << _fractionalBits));
}

float Fixed::toFloat( void ) const
{
    return ((float)_value / (float)(1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
    return (_value >> _fractionalBits);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "get_fractionalBitss member function called" << std::endl;
    return (_value);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "set_fractionalBitss member function called" << std::endl;
    _value = raw;
}