/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:09:14 by zvandeven         #+#    #+#             */
/*   Updated: 2024/01/18 16:49:13 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Weapon.hpp"

Weapon::Weapon(std::string name){
	this->setType(name);
}

Weapon::~Weapon(void){
}

const std::string& Weapon::getType(void)
{
	const std::string& stringREF = this->_type;

	return (stringREF);
}

void Weapon::setType(std::string newname)
{
	_type = newname;
}