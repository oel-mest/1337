#include "Animal.hpp"

Animal::Animal(void): type("default") {
    std::cout << "---Animal default constructor---" << std::endl;
}

Animal::Animal(std::string t): type(t) {
    std::cout << "---Animal type constructor---" << std::endl;
}

Animal::Animal(const Animal& other): type(other.type) {
    std::cout << "---Animal copy constructor---" << std::endl;
}

Animal::~Animal(void) {
    std::cout << "---Animal destructor---" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

const std::string& Animal::getType(void) const {
    return type;
}