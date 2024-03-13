/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:03:20 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/13 17:31:21 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
	ClapTrap i("1");

	i.attack("Ziggy");
	i.beRepaired(20);
	i.takeDamage(5);
	std::cout << "ClapTrap " << i.getName() << " has " << i.getHitPoints() << " Hitpoints." << std::endl;
	
	return (0);
}