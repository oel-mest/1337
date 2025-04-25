#include <iostream>
#include <fstream>

#include "SedReplace.hpp"

# define SUCCESS 0
# define FAILURE 1

int	main(int argc, char **argv) {
	SedReplace		*file;

	if (argc != 4) {
		std::cerr << "ex04: wrong number of arguments" << std::endl;
		std::cerr << "./ex04 <filename> \"string to replace\" \"replacement string\"" << std::endl;
		return (FAILURE);
	}

	file = new SedReplace(argv[1], argv[2], argv[3]);
	file->setNewName();
    if (file->checkFolder())
    {
        delete file;
        return (FAILURE);
    }
    if (!file->replace())
    {
        delete file;
        return (FAILURE);
    }
	delete file;
	return (SUCCESS);
}