/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:09:14 by zvandeven         #+#    #+#             */
/*   Updated: 2024/03/13 14:01:47 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Weapon.hpp"

Weapon::Weapon(std::string name) : _type(name) {
}

Weapon::~Weapon(void){
}

const std::string& Weapon::getType(void) const{
	const std::string& stringREF = this->_type;

	return (stringREF);
}

void Weapon::setType(std::string newname){
	_type = newname;
}