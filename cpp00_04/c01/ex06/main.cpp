#include "Harl.hpp"
#include <iostream>

int	main(void) {
	Harl	harl;

	std::cout << "Debug :" << std::endl;
	harl.complain("DEBUG");
	std::cout << "Info :" << std::endl;
	harl.complain("INFO");
	std::cout << "Warning :" << std::endl;
	harl.complain("WARNING");
	std::cout << "Error :" << std::endl;
	harl.complain("ERROR");
	std::cout << "tkhrmiza :" << std::endl;
	harl.complain("tkhrmiza");
	return (0);
}
