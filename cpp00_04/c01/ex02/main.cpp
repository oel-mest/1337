#include <string>
#include <iostream>

int main()
{
    std::string mystring = "HI THIS IS BRAIN";
    std::string *stringPTR = &mystring;
    std::string& stringREF = mystring;

    std::cout << "The memory address of the string : " << &mystring <<std::endl;
    std::cout << "The memory address held by stringPTR : " << stringPTR <<std::endl;
    std::cout << "The memory address held by stringPTR : " << &stringREF <<std::endl;
    std::cout << std::endl;
    std::cout << "The value of the string variable : " << mystring <<std::endl;
    std::cout << "The value pointed to by stringPTR : " << *stringPTR <<std::endl;
    std::cout << "The value pointed to by stringREF : " << stringREF <<std::endl;
    return 0;
}