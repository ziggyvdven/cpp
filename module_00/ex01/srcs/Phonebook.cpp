/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:22:59 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/07 13:54:25 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
# include <iomanip>
# include <string>
# include <sstream>
# include <cstdlib>

Phonebook::Phonebook(void)
{
	std::cout << "Phonebook created" << std::endl;
	return;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Phonebook destroyed" << std::endl;
	return;
}

std::string	Phonebook::get_entry(std::string msg) const
{
	std::string entry;

	while (!std::cin.eof() && entry == "")
	{
		std::cout << msg;
		entry = "";
		if ((getline(std::cin, entry) && entry != ""))
			return (entry);
		std::cout << R << " Field can't be empty" << END << std::endl;
	}
	exit(1);
}

int Phonebook::maxcontacts(std::string command) const
{
	static int contacts = 0;

	if (command != "ADD")
		return (contacts);
	if (contacts < 8)
	{
		contacts++;
		return (contacts);
	}
	std::cout << R << "[PHONEBOOK FULL] New contact will overwrite oldest entry." << END << std::endl;
	return (contacts);
}

std::string Phonebook::truncate(std::string string) const
{
	std::string NewString;
	
	if (string.length() <= 10)
		return (string);
	NewString = string.substr(0, 9);
	NewString += ".";
	return (NewString);
}

void	Phonebook::add(int i)
{	
	if (std::cin.eof())
		return;
	this->maxcontacts("ADD");
	this->contacts[i].setFirstName(get_entry("Enter first name    : "));
	this->contacts[i].setLastName(get_entry("Enter last name     : "));
	this->contacts[i].setNickName(get_entry("Enter nick name     : "));
	this->contacts[i].setPhoneNumber(get_entry("Enter phonenumber   : "));
	this->contacts[i].setDarkestSecret(get_entry("Enter darkest secret: "));
	std::cout << std::endl;
}

void	Phonebook::display(int i) const
{
	std::cout << std::endl << BOLD << "CONTACT INFORMATION:" << END << std::endl;
	std::cout << "First name     :" << this->contacts[i].getFirstName() << std::endl;
	std::cout << "Last name      :" << this->contacts[i].getLastName() << std::endl;
	std::cout << "Nick name      :" << this->contacts[i].getNickName() << std::endl;
	std::cout << "Phone number   :" << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret :" << this->contacts[i].getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

void	Phonebook::search() const
{
	int index;
	
	std::cout << std::endl << BOLD << "     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME" << END << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::right << std::setw(10) << i + 1 << '|';
		std::cout << std::right << std::setw(10) << this->truncate(this->contacts[i].getFirstName()) << '|';
		std::cout << std::right << std::setw(10) << this->truncate(this->contacts[i].getLastName()) << '|';
		std::cout << std::right << std::setw(10) << this->truncate(this->contacts[i].getNickName()) << std::endl;
	}
	std::cout << std::endl << "Enter index: ";
	std::string input;
	getline(std::cin, input);
	if (std::cin.eof())
		exit(1);
	std::istringstream result(input);
	if (!(result >> index) || index < 1 || index > 8 || input.length() == 0)
        std::cout << R << "[INVALID INPUT] Please enter a valid index." << END << std::endl;
	else if (index > this->maxcontacts("CHECK"))
		std::cout << R << "Contact is empty, please add more contacts." << END << std::endl;
	else 
		Phonebook::display(index - 1);
	return ;

}