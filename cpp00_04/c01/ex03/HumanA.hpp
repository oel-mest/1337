#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA{
    private:
        std::string name;
        Weapon &wp;
    public:
        HumanA(std::string name, Weapon &wp);
        ~HumanA(void);
        void    attack(void);
};

#endif // HUMANA_HPP