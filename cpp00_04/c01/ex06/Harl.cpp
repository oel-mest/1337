#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void) {
	std::cout << "\e[0;35m[ DEBUG ]" << std::endl;;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-i";
	std::cout << "specialketchup burger. I really do !\e[0m" << std::endl;
}

void	Harl::info(void) {
	std::cout << "\e[0;32m[ INFO ]" << std::endl;;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put ";
	std::cout << "enough bacon in my burger ! If you did, I wouldn’t be asking for more !\e[0m" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "\e[0;33m[ WARNING ]" << std::endl;;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming ";
	std::cout << "for years whereas you started working here since last month.\e[0m" << std::endl;
}

void	Harl::error(void) {
	std::cout << "\e[0;31m[ ERROR ]" << std::endl;;
	std::cout << "This is unacceptable ! I want to speak to the manager now.\e[0m" << std::endl;
}

void    Harl::complain(std::string level)
{
	int start = -1;
    void (Harl::*function[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string array[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (level == array[i])
        {
			start = i;
			break;
		}
    }
	switch (start)
	{
	case 0:
		(this->*function[0])();
	case 1:
		(this->*function[1])();
	case 2:
		(this->*function[2])();
	case 3:
		(this->*function[3])();
		break;
	default:
		std::cout << "\e[0;36m[ Probably complaining about insignificant problems ]\e[0m" << std::endl;
		break ;
	}
}