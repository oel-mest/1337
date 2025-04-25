#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int NUMBER_OF_ANIMALS = 50;
    Animal* animals[NUMBER_OF_ANIMALS];  // Array of Animal pointers

    // Fill the array with Dog and Cat objects
    for (int i = 0; i < NUMBER_OF_ANIMALS; i++) {
        if (i < NUMBER_OF_ANIMALS / 2) {
            animals[i] = new Dog();  // First half is Dog objects
        } else {
            animals[i] = new Cat();  // Second half is Cat objects
        }
    }

    // Test the array by making each animal sound
    for (int i = 0; i < NUMBER_OF_ANIMALS; i++) {
        animals[i]->makeSound();  // Polymorphic behavior
    }

    // Cleanup dynamically allocated memory
    for (int i = 0; i < NUMBER_OF_ANIMALS; i++) {
        delete animals[i];  // Properly delete each object
    }
	Dog basic;
	{
		Dog tmp = basic;
	}
	basic.get_ideas();
	return 0;
}
