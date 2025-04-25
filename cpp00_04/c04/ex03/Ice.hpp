#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		~Ice(void);
		Ice(Ice const & ref);
		Ice* clone() const;
		void use(ICharacter& target);
	private:
		Ice& operator=(Ice const & ref);
};

#endif