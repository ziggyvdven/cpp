/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:27:59 by zvandeven         #+#    #+#             */
/*   Updated: 2024/01/18 16:55:05 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/HumanB.hpp"

HumanB::HumanB(std::string human_name): _name(human_name), _weapon(NULL){}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack( void )
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
