#include "AMateria.hpp"

AMateria::AMateria(void) {
	// std::cout << "Abstract materia default constructor" << std::endl;
}

AMateria::AMateria(std::string const & t): type(t) {
	// std::cout << "Abstract materia type constructor" << std::endl;
}

AMateria::AMateria(AMateria const & other): type(other.type) {
	// std::cout << "Abstract materia copy constructor" << std::endl;
}

AMateria::~AMateria(void) {
	// std::cout << "Abstract materia destructor" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	// Makes no real sense, since 'type' is const and can't be assigned
	(void)other;
	return *this;
}

std::string const & AMateria::getType(void) const {
	return type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "* default materia use does nothing *" << std::endl;
}