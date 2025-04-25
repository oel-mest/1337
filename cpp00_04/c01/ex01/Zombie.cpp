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

void randomChump(std::string name)
{
    Zombie one(name);
    one.announce();
}

void    Zombie::setname(std::string name)
{
    this->name = name;
}

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cerr << "Negative numbers or 0 are not allowed" << std::endl;
        return NULL;
    }
    Zombie *array = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        array[i].setname(name);
    }
    return array;
}