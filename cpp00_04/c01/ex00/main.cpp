#include "Zombie.hpp"

int main()
{
    // Create a zombie on the heap
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    delete heapZombie;

    // Create and announce a zombie on the stack
    randomChump("StackZombie");

    return 0;
}
