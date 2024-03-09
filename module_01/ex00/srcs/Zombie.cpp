/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:36:07 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/02/29 17:23:52 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	return;
}

Zombie::~Zombie(void)
{
	std::cout << BOLD << this->_name  << " is destroyed" << END << std::endl;
	return;
}

void Zombie::announce(void) const
{
	std::cout << BOLD << this->_name  << ": BraiiiiiiinnnzzzZ..." << END << std::endl;
	return;
}