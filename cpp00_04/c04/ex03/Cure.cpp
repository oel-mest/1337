#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
    // std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure(void) {
    // std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(Cure const & ref) : AMateria(ref) {
    // std::cout << "Cure copy constructor called" << std::endl;
}

Cure* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
