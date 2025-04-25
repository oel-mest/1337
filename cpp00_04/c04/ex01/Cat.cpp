#include "Cat.hpp"

Cat::Cat(void): Animal("Cat"), brain(new Brain()) {
    std::cout << "---Cat default constructor---" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "---Cat copy constructor---" << std::endl;
}

Cat::~Cat(void) {
    delete brain;
    std::cout << "---Cat destructor---" << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "[SOUND] : Meowwww." << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return *this;
}

void Cat::get_ideas(void)
{
   brain->print_ideas();
}