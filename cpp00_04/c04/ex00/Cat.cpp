#include "Cat.hpp"

Cat::Cat(void): Animal("Cat") {
    std::cout << "---Cat default constructor---" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other) {
    std::cout << "---Cat copy constructor---" << std::endl;
}

Cat::~Cat(void) {
    std::cout << "---Cat destructor---" << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "[SOUND] : Meowwww." << std::endl;
}