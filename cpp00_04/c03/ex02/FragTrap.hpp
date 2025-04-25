#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(void);
        FragTrap(const FragTrap& other);
        FragTrap(std::string name);
        ~FragTrap(void);
        FragTrap& operator=(const FragTrap& other);
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif // FRAGTRAP_HPP