/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:03:20 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/15 14:21:31 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

int main()
{

		DiamondTrap	yoda("yoda");
		std::cout << "DiamondTrap " << BOLD << yoda.getName() << END << " has " << yoda.getHit() << " Hitpoints." << std::endl;
		std::cout << "DiamondTrap " << BOLD << yoda.getName() << END << " has " << yoda.getEnergy() << " Energy." << std::endl;
		std::cout << "DiamondTrap " << BOLD << yoda.getName() << END << " has " << yoda.getAttack() << " Attack point." << std::endl;
		yoda.attack("Mace Windu");
		yoda.highFivesGuys();
		yoda.guardGate();
		yoda.beRepaired(20);
		yoda.takeDamage(25);
		yoda.whoAmI();
	
	return (0);
}