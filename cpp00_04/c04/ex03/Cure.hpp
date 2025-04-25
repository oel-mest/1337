#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		~Cure(void);
		Cure(Cure const & ref);
		Cure *clone() const;
		void use(ICharacter& target);
	private:
		Cure & operator=(Cure const & ref);
};

#endif // CURE_HPP