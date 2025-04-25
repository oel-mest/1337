#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB{
    private:
        std::string name;
        Weapon *wp;
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void    setWeapon(Weapon &wp);
        void    attack(void);
};

#endif // HUMANB_HPP