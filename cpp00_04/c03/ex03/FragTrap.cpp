#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() {
    _health = 100;
    _attack = 30;
    _energy = 100;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
    _health = 100;
    _attack = 30;
    _energy = 100;
    std::cout << "FragTrap Name constructor called" << std::endl;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap " << _name << " has been destroyed\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap Assign operator called" << std::endl;
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (_energy > 0 && _health > 0) {
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
        _energy--;
    }
    else
        std::cout << "FragTrap " << _name << " cant attack (no energie or health points)" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    if (_energy > 0 && _health > 0) {
        std::cout << "FragTrap " << _name << " ask for a cool high fives" << std::endl;
        _energy--;
    }
    else
        std::cout << "FragTrap " << _name << " cant ask for a cool high fives (no energie or health points)" << std::endl;
}