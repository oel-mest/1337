#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat(void);
    WrongCat(const WrongCat& other);
    ~WrongCat(void);
    using WrongAnimal::operator=;
    void makeSound() const; 
};

#endif // WRONGCAT_HPP