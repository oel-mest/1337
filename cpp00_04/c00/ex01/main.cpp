/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:46:45 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/14 18:46:45 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void) {
    PhoneBook phone_book;
    std::string line;

    std::cout << "> ";
    while (std::getline(std::cin, line) && line != "EXIT")
    {
        if (line == "ADD")
            phone_book.Add();
        else if (line == "SEARCH")
            phone_book.Search();
        std::cout << "> ";
    }
    return 0;
}
