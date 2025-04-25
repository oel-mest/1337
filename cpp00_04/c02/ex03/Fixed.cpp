#include "Fixed.hpp"


Fixed::Fixed(void): _value(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): _value(other._value) {
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        _value = other._value;
    }
    // std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

std::ostream &operator<<(std::ostream &o, const Fixed &obj) {
	o << obj.toFloat();
	return (o);
}


Fixed::~Fixed(void) {
    // std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const int val) {
    // std::cout << "Int constructor called" << std::endl;
    _value = val << RawBit;
}

Fixed::Fixed(const float val) {
    // std::cout << "Float constructor called" << std::endl;
    _value = roundf(val * (1 << RawBit));
}

float Fixed::toFloat( void ) const {
    return ((float)_value / (float)(1 << RawBit));
}

int Fixed::toInt( void ) const {
    return (_value >> RawBit);
}

int Fixed::getRawBits( void ) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return (_value);
}

void Fixed::setRawBits( int const raw ) {
    // std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

bool Fixed::operator>(const Fixed& other) const {
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result._value = this->_value + other._value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result._value = this->_value - other._value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long temp = (this->_value) * other._value;
    result._value = (temp >> RawBit);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    if (other._value == 0) {
        std::cerr << "Erreur : Division by 0" << std::endl;
        result._value = 0;
    }
    else {
        long temp = (this->_value) << RawBit;
        result._value = (temp / other._value);
    }
    return result;
}

Fixed& Fixed::operator++() {
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++_value;
    return temp;
}

Fixed& Fixed::operator--() {
    --_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --_value;
    return temp;
}

Fixed& Fixed::min(Fixed& one, Fixed& two) {
    if (one > two)
        return two;
    return one;
}

Fixed& Fixed::max(Fixed& one, Fixed& two) {
    if (one > two)
        return one;
    return two;
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two) {
    if (one > two)
        return two;
    return one;
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two) {
    if (one > two)
        return one;
    return two;
}