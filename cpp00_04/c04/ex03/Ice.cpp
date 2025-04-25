#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {
    // std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice(void) {
    // std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(Ice const & ref) : AMateria(ref) {
    // std::cout << "Ice copy constructor called" << std::endl;
}

Ice* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
