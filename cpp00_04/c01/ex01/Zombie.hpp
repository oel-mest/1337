#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie(void);
        Zombie(std::string);
        ~Zombie(void);
        void    setname(std::string name);
        void    announce(void);
};

Zombie* newZombie( std::string name);
void randomChump( std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif // ZOMBIE_HPP