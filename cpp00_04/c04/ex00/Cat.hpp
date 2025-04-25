#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat(void);
    Cat(const Cat& other);
    ~Cat(void);
    using Animal::operator=;
    void makeSound() const; 
};

#endif // CAT_HPP