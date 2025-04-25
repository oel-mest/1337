#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog(void);
    Dog(const Dog& other);
    ~Dog(void);
    using Animal::operator=;
    void makeSound() const; 
};

#endif // DOG_HPP