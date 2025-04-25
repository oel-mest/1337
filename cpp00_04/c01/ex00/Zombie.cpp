#include "Zombie.hpp"

Zombie::Zombie(void): name("") {}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << ": Gone" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
    Zombie* ret = new Zombie(name);
    return ret;
}

void randomChump( std::string name)
{
    Zombie one(name);
    one.announce();
}