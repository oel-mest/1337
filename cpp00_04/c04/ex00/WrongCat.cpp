#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat") {
    std::cout << "---WrongCat default constructor---" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {
    std::cout << "---WrongCat copy constructor---" << std::endl;
}

WrongCat::~WrongCat(void) {
    std::cout << "---WrongCat destructor---" << std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << "[SOUND] : Meowwww." << std::endl;
}