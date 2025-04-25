/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:46:52 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/16 13:05:53 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        static const  int MAXSIZE = 8;
        Contact contacts[8];
    public:
        static  int _count;
        PhoneBook(void);
        ~PhoneBook(void);
        void    IncrementCount(void);
        int GetCount(void);
        void    Add(void);
        void    Search(void);
        void    PrintOneLine(void);
        void    PrintContact(int id);
        std::string    formatField(const std::string &str);
};

#endif // PHONEBOOK_HPP