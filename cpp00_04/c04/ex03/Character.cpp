#include "Character.hpp"

MateriaNode::MateriaNode(AMateria* materia) : m(materia), next(NULL) {}

Character::Character(void) : _name("") {
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	_head = NULL;
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	_head = NULL;
}

Character::Character(const Character& other): _name(other._name) {
	for (int i = 0; i < 4; ++i) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; ++i) {
			if (_inventory[i]) {
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] != NULL) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	MateriaNode* tmp;
	while (_head)
	{
		tmp = _head;
		_head = _head->next;
		delete tmp->m;
		delete tmp;
	}
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		MateriaNode* node = new MateriaNode(_inventory[idx]);
		node->next = _head;
		_head = node;
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		_inventory[idx]->use(target);
	}
}