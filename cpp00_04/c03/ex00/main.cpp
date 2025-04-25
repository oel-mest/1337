#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap a("Mr ClapTrap");
	ClapTrap b(a);
	ClapTrap c("Mrs ClapTrap");
	ClapTrap d;
    d = c;
	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "b: ";
	b.attack("some random guy");
	std::cout << "c: ";
	c.attack("some random guy");
	std::cout << "d: ";
	d.attack("some random guy");

	std::cout << "a: ";
	a.takeDamage(3);
	std::cout << "b: ";
	b.takeDamage(5);
	std::cout << "c: ";
	c.takeDamage(7);
	std::cout << "d: ";
	d.takeDamage(12);

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
	a.takeDamage(5);
	std::cout << "a: ";
	a.beRepaired(4);
	std::cout << "a: ";
	a.takeDamage(5);
	std::cout << "a: ";
	a.beRepaired(8);
	std::cout << "a: ";
	a.takeDamage(5);
	std::cout << "a: ";
	a.beRepaired(4);
	std::cout << "a: ";
	a.takeDamage(5);
	std::cout << "a: ";
	a.beRepaired(4);
	std::cout << "a: ";
	a.takeDamage(5);
	std::cout << "a: ";
	a.beRepaired(4);
	std::cout << "a: ";
	a.takeDamage(5);
	std::cout << "a: ";
	a.beRepaired(4);
	std::cout << "a: ";
	a.beRepaired(4);
	std::cout << "a: ";
	a.attack("some random guy");
	std::cout << "a: ";
	a.takeDamage(5);
	std::cout << "a: ";
	a.attack("some random guy");
	return(0);
}
