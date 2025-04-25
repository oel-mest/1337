#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
    Brain(void);
    Brain(const Brain& other);
    ~Brain(void);
    Brain& operator=(const Brain& other);
    void print_ideas(void);
private:
    std::string ideas[100];
};

#endif // BRAIN_HPP