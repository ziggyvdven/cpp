/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:23:14 by zvandeven         #+#    #+#             */
/*   Updated: 2024/01/17 17:14:30 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>

int	main()
{
	//A string variable initialized to "HI THIS IS BRAIN".
	std::string string = "HI THIS IS BRIAN";
	
	// stringPTR: A pointer to the string.
	std::string *stringPTR = &string;
	
	// stringREF: A reference to the string.
	std::string &stringREF = string;

	// The memory address of the string variable.
	std::cout << "The memory address of the string variable: " << &string << std::endl;
	
	// The memory address held by stringPTR.
	std::cout << "The memory address held by stringPTR.:     " << stringPTR << std::endl;
	
	// The memory address held by stringREF.
	std::cout << "The memory address held by stringREF.:     " << &stringREF << std::endl;

	// The value of the string variable.
	std::cout << "The value of the string variable:  " << string << std::endl;

	// The value pointed to by stringPTR.
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;

	// The value pointed to by stringREF.
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}