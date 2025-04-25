#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), wp(NULL) {
    std::cout << name << " created with no weapon" << std::endl;
}

HumanB::~HumanB(void) {}

void    HumanB::attack(void)
{
    if (this->wp)
		std::cout << name << " attacks with their " << this->wp->getType() << std::endl;
	else
		std::cout << name << " attacks with their hands" << std::endl;
}

void HumanB::setWeapon(Weapon &wp)
{
    this->wp = &wp;
    std::cout << name << " get weapon " << this->wp->getType() << std::endl;
}