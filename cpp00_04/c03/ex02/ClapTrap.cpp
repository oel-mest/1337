#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(void): _name("Default name"), _health(10), _energy(10), _attack(0) {
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), _health(other._health),  _energy(other._energy), _attack(other._attack) {
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _health(10), _energy(10), _attack(0) {
    std::cout << "Name constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _health = other._health;
        _energy = other._energy;
        _attack = other._attack;
    }
    std::cout << "Assign operator called" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (_energy > 0 && _health > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << std::endl;
        _energy--;
    }
    else
        std::cout << "ClapTrap " << _name << " cant attack (no energie or health points)" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_health < amount)
        _health = 0;
    else
        _health -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energy > 0 && _health > 0) {
        std::cout << "ClapTrap " << _name << " is repaired for " << amount << " health points!" << std::endl;
        _energy--;
        _health += amount;
    }
    else
        std::cout << "ClapTrap " << _name << " cant be repaired (no energy or health) " << std::endl;
}