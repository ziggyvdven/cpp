/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:09:14 by zvandeven         #+#    #+#             */
/*   Updated: 2024/01/15 17:04:23 by zvandeven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Weapon.hpp"

Weapon::Weapon(std::string name){
	this->setType(name);
}

Weapon::~Weapon(){

}

const std::string& Weapon::getType(void)
{
	const std::string& stringREF = this->_type;

	return (stringREF);
}

void Weapon::setType(std::string newName)
{
	this->_type = newName;
}