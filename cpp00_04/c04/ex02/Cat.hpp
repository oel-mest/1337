#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
    Cat(void);
    Cat(const Cat& other);
    ~Cat(void);
    Cat& operator=(const Cat& other);
    void makeSound() const;
    void get_ideas(void);
private:
    Brain *brain;
};

#endif // CAT_HPP