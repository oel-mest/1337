#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nAnimal testing" << std::endl;
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\nWrong Animal testing\n" << std::endl;
	WrongAnimal	*wrongAnimal = new WrongAnimal;
	WrongAnimal	*wrongCat = new WrongCat;

	std::cout << "\nWrongAnimal: ";
	wrongAnimal->makeSound();
	std::cout << "WrongCat: ";
	wrongCat->makeSound();
	std::cout << std::endl;
	delete wrongAnimal;
	delete wrongCat;
}