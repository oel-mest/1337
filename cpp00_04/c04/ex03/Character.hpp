#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

struct MateriaNode {
	AMateria* m;
	MateriaNode* next;
	MateriaNode(AMateria* materia);
};

class Character: public ICharacter {
	private:
		std::string _name;
		AMateria* _inventory[4];
		MateriaNode* _head;
	public:
		Character(void);
		Character(const std::string& name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif // CHARACTER_HPP