#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap() {
    _health = 100;
    _attack = 20;
    _energy = 50;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
    _health = 100;
    _attack = 20;
    _energy = 50;
    std::cout << "ScavTrap Name constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap " << _name << " has been destroyed\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap Assign operator called" << std::endl;
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (_energy > 0 && _health > 0) {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
        _energy--;
    }
    else
        std::cout << "ScavTrap " << _name << " cant attack (no energie or health points)" << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}