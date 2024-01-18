/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:35:40 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/01/18 17:09:39 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <thread>

int main() 
{
	std::cout << G << "Zombie horde!! Created on the heap it will have to be be deleted manually" << END << std::endl;
	Zombie* zombiehorde = zombieHorde( 10, "Olivier" );
	delete[] zombiehorde;
	return (0);
}