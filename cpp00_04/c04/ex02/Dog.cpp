#include "Dog.hpp"

Dog::Dog(void): Animal("Dog"), brain(new Brain()) {
    std::cout << "---Dog default constructor---" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "---Dog copy constructor---" << std::endl;
}

Dog::~Dog(void) {
    delete brain;
    std::cout << "---Dog destructor---" << std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "[SOUND] : Woof, woof." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return *this;
}

void Dog::get_ideas(void)
{
   brain->print_ideas();
}