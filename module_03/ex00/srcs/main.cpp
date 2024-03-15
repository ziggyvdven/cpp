/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:03:20 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/14 13:12:19 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
	{
	ClapTrap i("Palpetine");

		i.attack("Luke");
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getHit() << " Hitpoints." << std::endl;
		i.beRepaired(20);
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getHit() << " Hitpoints." << std::endl;
		i.takeDamage(25);
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getHit() << " Hitpoints." << std::endl;
		i.takeDamage(15);
		i.beRepaired(20);
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getHit() << " Hitpoints." << std::endl;
	}
	ClapTrap i("Somehow palpetine returned");
	{
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getEnergy() << " Energy." << std::endl;
		i.attack("Luke");
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getEnergy() << " Energy." << std::endl;
		i.attack("Luke");
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getEnergy() << " Energy." << std::endl;
		i.attack("Luke");
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getEnergy() << " Energy." << std::endl;
		i.attack("Luke");
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getEnergy() << " Energy." << std::endl;
		i.attack("Luke");
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getEnergy() << " Energy." << std::endl;
		i.attack("Luke");
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getEnergy() << " Energy." << std::endl;
		i.attack("Luke");
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getEnergy() << " Energy." << std::endl;
		i.attack("Luke");
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getEnergy() << " Energy." << std::endl;
		i.attack("Luke");
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getEnergy() << " Energy." << std::endl;
		i.attack("Luke");
		std::cout << "ClapTrap " << BOLD << i.getName() << END << " has " << i.getEnergy() << " Energy." << std::endl;
		i.attack("Luke");
		
	}
	
	return (0);
}