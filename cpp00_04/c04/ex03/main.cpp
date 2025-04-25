#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
	std::cout << "=== MateriaSource learning phase ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "=== Creating Materias from source ===" << std::endl;
	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");
	AMateria* unknown = src->createMateria("fire");

	std::cout << (ice ? "✅ Created Ice" : "❌ Ice not created") << std::endl;
	std::cout << (cure ? "✅ Created Cure" : "❌ Cure not created") << std::endl;
	std::cout << (unknown ? "❌ Shouldn't create unknown" : "✅ Unknown returned null") << std::endl;

	std::cout << "=== Character equipping and using Materias ===" << std::endl;
	ICharacter* cloud = new Character("Cloud");
	cloud->equip(ice);
	cloud->equip(cure);
	cloud->equip(unknown);  // should do nothing

	ICharacter* enemy = new Character("Sephiroth");

	cloud->use(0, *enemy); // use Ice
	cloud->use(1, *enemy); // use Cure
	cloud->use(2, *enemy); // empty or invalid

	std::cout << "=== Unequip a Materia ===" << std::endl;
	cloud->unequip(0); // ice unequipped
	cloud->unequip(100);
	std::cout << "Try using slot 0 again (should do nothing):" << std::endl;
	cloud->use(0, *enemy); // should do nothing

	std::cout << "=== Cleanup ===" << std::endl;
	delete src;
	delete cloud;
	delete enemy;
	return 0;
}
