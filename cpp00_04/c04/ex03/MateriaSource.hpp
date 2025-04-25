#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* _templates[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		~MateriaSource(void);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif // MATERIASOURCE_HPP