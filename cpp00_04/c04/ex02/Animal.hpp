#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
class Animal
{
public:
    Animal(void);
    Animal(const Animal& other);
    Animal(std::string t);
    virtual ~Animal(void);
    Animal& operator=(const Animal& other);
    virtual void makeSound() const = 0;
    const std::string& getType(void) const;
protected:
    std::string type;
};

#endif // ANIMAL_HPP