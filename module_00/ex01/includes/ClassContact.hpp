/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:05:14 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/02/29 17:12:31 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "Phonebook.hpp"
#include "../includes/Phonebook.hpp"

class Contact 
{
  private:
  	std::string _FirstName;
	std::string _LastName;
	std::string _NickName;
	std::string _PhoneNumber;
	std::string _DarkestSecret;
	
  public:
	Contact(void);
	~Contact(void);
	void setFirstName(std::string str);
	void setLastName(std::string str);
	void setNickName(std::string str);
	void setPhoneNumber(std::string str);
	void setDarkestSecret(std::string str);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;	
};

#endif