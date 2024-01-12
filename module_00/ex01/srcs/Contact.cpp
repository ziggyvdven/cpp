/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:22:59 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/01/12 14:56:20 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}
void Contact::setFirstName(std::string str)
{
	_FirstName = str;
	return;
}

void Contact::setLastName(std::string str)
{
	_LastName = str;
	return;
}

void Contact::setNickName(std::string str)
{
	_NickName = str;
	return;
}

void Contact::setPhoneNumber(std::string str)
{
	_PhoneNumber = str;
	return;
}

void Contact::setDarkestSecret(std::string str)
{
	_DarkestSecret = str;
	return;
}

std::string Contact::getFirstName()
{
	return (Contact::_FirstName);
}

std::string Contact::getLastName()
{
	return (Contact::_LastName);
}

std::string Contact::getNickName()
{
	return (Contact::_NickName);
}

std::string Contact::getPhoneNumber()
{
	return (Contact::_PhoneNumber);
}

std::string Contact::getDarkestSecret()
{
	return (Contact::_DarkestSecret);
}
