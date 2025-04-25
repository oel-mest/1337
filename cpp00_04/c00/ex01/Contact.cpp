/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:46:38 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/14 18:46:39 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void): _fname(""), _lname(""), _nname(""), _phone(""), _secret("") {}

Contact::~Contact(void) {}

int	Contact::IsPrintable(std::string tocheck)
{
	for (size_t i = 0; i < tocheck.length(); i++)
    {
        if (!isprint(tocheck[i]))
            return 0;
    }
    return 1; 
}

void Contact::SetFname(void)
{
    std::cout << "Enter First name : ";
    do {
        getline(std::cin, this->_fname);
    } while (this->_fname.empty() || !IsPrintable(this->_fname));
}

void Contact::SetLname(void)
{
    std::cout << "Enter Last name : ";
    do {
        getline(std::cin, this->_lname);
    } while (this->_lname.empty() || !IsPrintable(this->_lname));
}

void Contact::SetNname(void)
{
    std::cout << "Enter Nickname : ";
    do {
        getline(std::cin, this->_nname);
    } while (this->_nname.empty() || !IsPrintable(this->_nname));
}

void Contact::SetPhone(void)
{
    std::cout << "Enter Phone Number: ";
    do {
        getline(std::cin, this->_phone);
    } while (this->_phone.empty() || !IsPrintable(this->_phone));
}

void Contact::SetSecret(void)
{
    std::cout << "Enter Darkest Secret : ";
    do {
        getline(std::cin, this->_secret);
    } while (this->_secret.empty() || !IsPrintable(this->_secret));
}

std::string Contact::GetFname(void)
{
	return this->_fname;
}

std::string Contact::GetLname(void)
{
	return this->_lname;
}

std::string Contact::GetNname(void)
{
	return this->_nname;
}

std::string Contact::GetPhone(void)
{
	return this->_phone;
}

std::string Contact::GetSecret(void)
{
	return this->_secret;
}