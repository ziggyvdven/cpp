/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:35:40 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/01/17 18:44:25 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <thread>

int main() 
{
	std::cout << G << "Zombie created normally called henk, class will be destroyed when main is finished: " << END << std::endl;
	Zombie zombie1("Henk");
	zombie1.announce();
	
	std::cout << G << "Zombie \"Harry\" created (heap) using function newZombie, pointer can be used outside of scope but has the be deleted manually: " << END << std::endl;
	Zombie *ptr = newZombie("Harry");
	ptr->announce();
	std::cout << R << "Zombie \"Harry\" will be destroyed manually" << END << std::endl;
	delete (ptr);

	std::cout << G << "Zombie horde!! created (heap) will be deleted manually" << END << std::endl;
	Zombie* zombiehorde = zombieHorde( 10, "Olivier" );
	delete[] zombiehorde;
	
	std::cout << R << "Zombie henk will be destroyed when main finishes " << END << std::endl;
	return (0);
}