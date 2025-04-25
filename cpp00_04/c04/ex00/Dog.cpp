#include "Dog.hpp"

Dog::Dog(void): Animal("Dog") {
    std::cout << "---Dog default constructor---" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other) {
    std::cout << "---Dog copy constructor---" << std::endl;
}

Dog::~Dog(void) {
    std::cout << "---Dog destructor---" << std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "[SOUND] : Woof, woof." << std::endl;
}