#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wp): name(name), wp(wp) {
    std::cout << name << " created with " << this->wp.getType() << std::endl;
}

HumanA::~HumanA(void) {}

void    HumanA::attack(void)
{
    std::cout << name << " attacks with their " << this->wp.getType() << std::endl;
}

