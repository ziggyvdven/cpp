/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:50:29 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/01/12 14:54:42 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

int main() 
{
	std::string command;
	Phonebook Phonebook;
	int i = -1;
	
	while (1)
	{
		std::cout << "Enter a command [ADD, SEARCH and EXIT]: ";
		getline(std::cin, command);
		if (command.length() == 0 && !std::cin.eof())
			continue;
		if (command == "ADD")
			Phonebook.add(++i);
		else if (command == "SEARCH")
			Phonebook.search();
		else if (command == "EXIT" || std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}
		else
			std::cout << "COMMAND NOT FOUND" << std::endl;
		if (i == 7)
			i = -1;
	}
	return (0);
}
