#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    Animal* fff = new Dog(); // or new Cat();
    fff->makeSound();
    delete fff;
}
