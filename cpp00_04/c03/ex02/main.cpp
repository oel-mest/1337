#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // Creating instances of each class
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavy");
    FragTrap frag("Fraggy");

    std::cout << std::endl;

    // Demonstrating attack behavior
    clap.attack("Target A");
    scav.attack("Target B");
    frag.attack("Target C");

    std::cout << std::endl;

    // Demonstrating damage and repair
    clap.takeDamage(5);
    clap.beRepaired(3);

    scav.takeDamage(20);
    scav.beRepaired(10);

    frag.takeDamage(15);
    frag.beRepaired(5);

    std::cout << std::endl;

    // Demonstrating class-specific behaviors
    scav.guardGate();
    frag.highFivesGuys();

    std::cout << std::endl;

    return 0;
}
