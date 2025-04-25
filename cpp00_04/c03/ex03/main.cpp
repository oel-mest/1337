// main.cpp
#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    // 1. Default constructor
    DiamondTrap dt1;
    std::cout << "---- dt1 created with default ctor ----\n\n";

    // 2. Name constructor
    DiamondTrap dt2("Gemini");
    std::cout << "\n---- dt2 created with name ctor ----\n";
    dt2.attack("Goblin");
    dt2.whoAmI();
    std::cout << '\n';

    // 3. Copy constructor
    DiamondTrap dt3(dt2);
    std::cout << "\n---- dt3 created by copy ctor ----\n";
    dt3.whoAmI();
    std::cout << '\n';

    // 4. Assignment operator
    DiamondTrap dt4;
    dt4 = dt3;
    std::cout << "\n---- dt4 assigned from dt3 ----\n";
    dt4.whoAmI();
    std::cout << '\n';

    // 5. Modify dt4 and show independence
    dt4.attack("Orc");
    dt4.whoAmI();
    std::cout << "\n---- End of tests, destructors will run ----\n";

    return 0;
}
