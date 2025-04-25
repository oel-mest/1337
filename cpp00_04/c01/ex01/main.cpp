#include "Zombie.hpp"

int main() {
    int N = 5; // Number of zombies to create
    Zombie* horde = zombieHorde(N, "HordeZombie");
    
    if (!horde) {
        std::cerr << "Error: Could not allocate zombie horde." << std::endl;
        return 1;
    }
    
    // Each zombie announces itself
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    
    // Clean up the allocated memory
    delete[] horde;
    return 0;
}