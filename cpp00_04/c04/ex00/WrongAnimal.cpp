#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("default") {
    std::cout << "---WrongAnimal default constructor---" << std::endl;
}

WrongAnimal::WrongAnimal(std::string t): type(t) {
    std::cout << "---WrongAnimal name constructor---" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type) {
    std::cout << "---WrongAnimal copy constructor---" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "---WrongAnimal destructor---" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "[SOUND] : I'm just an WrongAnimal." << std::endl;
}

const std::string& WrongAnimal::getType(void) const {
    return type;
}