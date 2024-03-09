/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:23:14 by zvandeven         #+#    #+#             */
/*   Updated: 2024/03/07 11:28:52 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Replace.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 4)
	{
		Replace replace(argv[2], argv[3]);
		if (!replace.setIfsOfs(argv[1]))
			std::cout << "Unable to open file [" << argv[1] << "]" << std::endl;
		else
		{
			if (replace.findandreplace())
				std::cout << "[" << argv[1] << ".replace] created succesfully" << std::endl;
			else
				std::cout << "Replacement not possible" << std::endl;
		}		
	}
	else
		std::cout << "Please enter 3 parameters: filename and two strings, s1 and s2." << std::endl;
	return 0; 
}
