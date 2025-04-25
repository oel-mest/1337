#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "---Brain default constructor---" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "---Brain copy constructor---" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain::~Brain(void) {
    std::cout << "---Brain destructor---" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "---Brain operator =---" << std::endl;

    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

void Brain::print_ideas(void)
{
    for (int i = 0; i < 100 ; i++)
    {
        std::cout << "idea[" << i << "] :" << ideas[i] << std::endl;
    }
}