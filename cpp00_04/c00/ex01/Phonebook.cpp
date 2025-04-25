/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:46:48 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/14 18:46:48 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "PhoneBook.hpp"

int PhoneBook::_count = 0;

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::IncrementCount(void) {
    _count++;
}

int PhoneBook::GetCount(void) {
    return (this->_count);
}

void PhoneBook::Add(void)
{
    contacts[PhoneBook::GetCount() % this->MAXSIZE].SetFname();
    contacts[PhoneBook::GetCount() % this->MAXSIZE].SetLname();
    contacts[PhoneBook::GetCount() % this->MAXSIZE].SetNname();
    contacts[PhoneBook::GetCount() % this->MAXSIZE].SetPhone();
    contacts[PhoneBook::GetCount() % this->MAXSIZE].SetSecret();
    PhoneBook::IncrementCount();
}

void PhoneBook::Search(void)
{
    if (_count == 0) {
        std::cout << "No contacts available. Please add a contact first." << std::endl;
        return;
    }
    PrintOneLine();
    std::string input;
    int index = -1;
    int realindex = _count < 8 ? _count - 1 : 7;
    while (true)
    {
        std::cout << "Enter a valid index (0-" << realindex  << "): ";
        if (!std::getline(std::cin, input)) {
            std::cout << "Error reading input. Aborting search." << std::endl;
            return;
        }
        std::istringstream iss(input);
        if (!(iss >> index)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }
        if (index < 0 || index > realindex) {
            std::cout << "Index out of range. Please try again." << std::endl;
            continue;
        }
        break;
    }
    PrintContact(index);
}

std::string PhoneBook::formatField(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else {
        std::ostringstream oss;
        oss << std::setw(10) << str;
        return oss.str();
    }
}

void    PhoneBook::PrintOneLine(void)
{
    for (int i = 0; i < this->_count && i < this->MAXSIZE; i++) {
        if (!this->contacts[i].GetFname().empty())
        {
            std::cout << std::setw(10) << i << "|"
                    << formatField(this->contacts[i].GetFname()) << "|"
                    << formatField(this->contacts[i].GetLname()) << "|"
                    << formatField(this->contacts[i].GetNname()) << std::endl;
        }
    }
}

void    PhoneBook::PrintContact(int index)
{
	std::cout << "---------------------------------" << std::endl;
    std::cout << "First name : " << this->contacts[index].GetFname() << std::endl;
    std::cout << "Last name : " << this->contacts[index].GetLname() << std::endl;
    std::cout << "Nickname : " << this->contacts[index].GetNname() << std::endl;
    std::cout << "Phone : " << this->contacts[index].GetPhone() << std::endl;
    std::cout << "Deepest Secret : " << this->contacts[index].GetSecret() << std::endl;
	std::cout << "---------------------------------" << std::endl;
}