/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:23:14 by zvandeven         #+#    #+#             */
/*   Updated: 2024/02/29 19:07:09 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Weapon.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 4)
	{
		std::ifstream ifs(argv[1]);
		std::string input;
		std::string replace = ".replace";
		std::string newfile = argv[1] + replace;
		std::ofstream ofs(newfile);
		while(1)
		{
			getline(ifs, input);
			if (input.find(argv[2]) != std::string::npos)
				std::cout << "FOUND: " << argv[2] << "!" << std::endl;
			ofs << input;
			if (ifs.eof() == true)
				break ;
			ofs << std::endl;
		}
		ifs.close();
		ofs.close();
		
	}
	else
	std::cout << "Please enter 3 parameters: filename and two strings, s1 and s2." << std::endl;
	return 0; 
}
