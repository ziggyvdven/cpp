/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:03:20 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/28 13:39:11 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main()
{
	{
	ClapTrap emperor("Palpetine");

		emperor.attack("Mace Windu");
		std::cout << "ClapTrap " << BOLD << emperor.getName() << END << " has " << emperor.getHit() << " Hitpoints." << std::endl;
		emperor.beRepaired(20);
		std::cout << "ClapTrap " << BOLD << emperor.getName() << END << " has " << emperor.getHit() << " Hitpoints." << std::endl;
		emperor.takeDamage(25);
		std::cout << "ClapTrap " << BOLD << emperor.getName() << END << " has " << emperor.getHit() << " Hitpoints." << std::endl;
		emperor.takeDamage(15);
		emperor.beRepaired(20);
		std::cout << "ClapTrap " << BOLD << emperor.getName() << END << " has " << emperor.getHit() << " Hitpoints." << std::endl;
	}
		std::cout << std::endl;
	{
		ClapTrap emperor2("Somehow palpetine returned");
		std::cout << "ClapTrap " << BOLD << emperor2.getName() << END << " has " << emperor2.getEnergy() << " Energy." << std::endl;
		emperor2.attack("Rey");
		std::cout << "ClapTrap " << BOLD << emperor2.getName() << END << " has " << emperor2.getEnergy() << " Energy." << std::endl;
		emperor2.attack("Rey");
		std::cout << "ClapTrap " << BOLD << emperor2.getName() << END << " has " << emperor2.getEnergy() << " Energy." << std::endl;
		emperor2.attack("Rey");
		std::cout << "ClapTrap " << BOLD << emperor2.getName() << END << " has " << emperor2.getEnergy() << " Energy." << std::endl;
		emperor2.attack("Rey");
		std::cout << "ClapTrap " << BOLD << emperor2.getName() << END << " has " << emperor2.getEnergy() << " Energy." << std::endl;
		emperor2.attack("Rey");
		std::cout << "ClapTrap " << BOLD << emperor2.getName() << END << " has " << emperor2.getEnergy() << " Energy." << std::endl;
		emperor2.attack("Rey");
		std::cout << "ClapTrap " << BOLD << emperor2.getName() << END << " has " << emperor2.getEnergy() << " Energy." << std::endl;
		emperor2.attack("Rey");
		std::cout << "ClapTrap " << BOLD << emperor2.getName() << END << " has " << emperor2.getEnergy() << " Energy." << std::endl;
		emperor2.attack("Rey");
		std::cout << "ClapTrap " << BOLD << emperor2.getName() << END << " has " << emperor2.getEnergy() << " Energy." << std::endl;
		emperor2.attack("Rey");
		std::cout << "ClapTrap " << BOLD << emperor2.getName() << END << " has " << emperor2.getEnergy() << " Energy." << std::endl;
		emperor2.attack("Rey");
		std::cout << "ClapTrap " << BOLD << emperor2.getName() << END << " has " << emperor2.getEnergy() << " Energy." << std::endl;
		emperor2.attack("Rey");
	}
		std::cout << std::endl;
	{
		ScavTrap sith("Vader");
		sith.attack("Luke");
		std::cout << "ScavTrap " << BOLD << sith.getName() << END << " has " << sith.getHit() << " Hitpoints." << std::endl;
		sith.takeDamage(10);
		std::cout << "ScavTrap " << BOLD << sith.getName() << END << " has " << sith.getHit() << " Hitpoints." << std::endl;
		sith.beRepaired(5000);
		std::cout << "ScavTrap " << BOLD << sith.getName() << END << " has " << sith.getHit() << " Hitpoints." << std::endl;
		std::cout << "ScavTrap " << BOLD << sith.getName() << END << " has " << sith.getEnergy() << " Energy." << std::endl;
		sith.guardGate();
	}
		std::cout << std::endl;
	{
		FragTrap jedi("luke");
		jedi.attack("Vader");
		jedi.attack("Vader");
		jedi.attack("Vader");
		jedi.highFivesGuys();
		std::cout << "ClapTrap " << BOLD << jedi.getName() << END << " has " << jedi.getHit() << " Hitpoints." << std::endl;
		jedi.takeDamage(200);
		std::cout << "ClapTrap " << BOLD << jedi.getName() << END << " has " << jedi.getHit() << " Hitpoints." << std::endl;
		jedi.highFivesGuys();
		
	}
	
	return (0);
}