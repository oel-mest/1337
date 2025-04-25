#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
    protected:
        std::string _name;
        unsigned int _health;
        unsigned int _energy;
        unsigned int _attack;
    public:
        ClapTrap(void);
        ClapTrap(const ClapTrap& other);
        ClapTrap(std::string name);
        virtual ~ClapTrap(void);
        ClapTrap& operator=(const ClapTrap& other);
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP