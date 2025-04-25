#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int _value;
        static const int _fractionalBits = 8;
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
};

std::ostream &operator<<(std::ostream &o, const Fixed &obj);

#endif // FIXED_HPP