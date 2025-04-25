#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int _value;
        static const int RawBit = 8;
    public:
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed(const int val);
        Fixed(const float val);
        Fixed& operator=(const Fixed& other);
        ~Fixed(void);
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        // comparaison
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        // op
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        // inc decre
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        // functions
        static Fixed& min(Fixed& one, Fixed& two);
        static const Fixed& min(const Fixed& one, const Fixed& two);

        static Fixed& max(Fixed& one, Fixed& two);
        static const Fixed& max(const Fixed& one, const Fixed& two);
};

std::ostream &operator<<(std::ostream &o, const Fixed &obj);

#endif // FIXED_HPP