/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:47:00 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/16 12:59:21 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_HPP
#define MEGAPHONE_HPP

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        for (int i = 1; i < argc; ++i)
        {
            std::string word(argv[i]);
            for (std::string::size_type j = 0; j < word.length(); ++j)
            {
                std::cout << (char)std::toupper(word[j]);
            }
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}

#endif // MEGAPHONE_HPP