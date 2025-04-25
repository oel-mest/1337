#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name") {
    this->_name = "Default";
    _health = 100;
    _attack = 30;
    _energy = 50;
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
  : ClapTrap(other)
  , ScavTrap(other)
  , FragTrap(other)
  , _name(other._name)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name")
, ScavTrap(name + "_clap_name")
, FragTrap(name + "_clap_name")
{
    this->_name = name;
    _health = 100;
    _attack = 30;
    _energy = 50;
    std::cout << "DiamondTrap Name constructor calledd" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap " << this->_name << " has been destroyed\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    std::cout << "DiamondTrap Assign operator called" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI(void) {
    std::cout << "My name is " << _name << " and the ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}