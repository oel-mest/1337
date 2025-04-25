#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
class WrongAnimal
{
public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal(std::string t);
    ~WrongAnimal(void);
    WrongAnimal& operator=(const WrongAnimal& other);
    void makeSound() const;
    const std::string& getType(void) const;
protected:
    std::string type;
};

#endif // WRONGANIMAL_HPP