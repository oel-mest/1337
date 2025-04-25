#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	public:
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap(const std::string name);
		~DiamondTrap(void);
		DiamondTrap& operator=(const DiamondTrap& other);

		void attack(const std::string& target);
		void whoAmI(void);
	private:
		std::string _name;
};

#endif // DIAMONDTRAP_HPP