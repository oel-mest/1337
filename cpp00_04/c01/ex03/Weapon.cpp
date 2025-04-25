#include "Weapon.hpp"

Weapon::Weapon(std::string wtype)
{
    type = wtype;
}

Weapon::~Weapon(void) {}

const std::string& Weapon::getType() const
{
    return type;
}

void    Weapon::setType(std::string t)
{
    type = t;
}