#include "ScavTrap.hpp"
#include <iostream>

int	main(void) {
	ScavTrap a("Mr ScavTrap");
	ScavTrap b(a);
	ScavTrap c("Mrs ScavTrap");
	ScavTrap d = c;

	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "b: ";
	b.attack("some random guy");
	std::cout << "c: ";
	c.attack("some random guy");
	std::cout << "d: ";
	d.attack("some random guy");

	std::cout << "a: ";
	a.takeDamage(30);
	std::cout << "b: ";
	b.takeDamage(50);
	std::cout << "c: ";
	c.takeDamage(70);
	std::cout << "d: ";
	d.takeDamage(120);

	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "b: ";
	b.attack("some random guy");
	std::cout << "c: ";
	c.attack("some random guy");
	std::cout << "d: ";
	d.attack("some random guy");

	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(80);
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.attack("some random guy");
	for (int i = 0; i < 40; i++) {
		std::cout << "a: ";
		a.attack("some random guy");
	}
	std::cout << "a: ";
	a.beRepaired(40);
	std::cout << "a: ";
	a.takeDamage(50);
	std::cout << "a: ";
	a.beRepaired(40);

	std::cout << "a: ";
	a.guardGate();
	std::cout << "b: ";
	b.guardGate();
	std::cout << "b: ";
	b.guardGate();
	std::cout << "b: ";
	b.guardGate();
	return(0);
}
