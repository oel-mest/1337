#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(void);
        ScavTrap(const ScavTrap& other);
        ScavTrap(std::string name);
        ~ScavTrap(void);
        ScavTrap& operator=(const ScavTrap& other);
        void attack(const std::string& target);
        void guardGate(void);
};

#endif // SCAVTRAP_HPP