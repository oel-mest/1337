/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mest <oel-mest@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:46:42 by oel-mest          #+#    #+#             */
/*   Updated: 2025/04/16 12:50:23 by oel-mest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string _fname;
        std::string _lname;
        std::string _nname;
        std::string _phone;
        std::string _secret;
    public:
        Contact(void);
        ~Contact(void);
        int IsPrintable(std::string tocheck);
        void SetFname(void);
        void SetLname(void);
        void SetNname(void);
        void SetPhone(void);
        void SetSecret(void);
        std::string GetFname(void);
        std::string GetLname(void);
        std::string GetNname(void);
        std::string GetPhone(void);
        std::string GetSecret(void);
};

#endif // CONTACT_HPP