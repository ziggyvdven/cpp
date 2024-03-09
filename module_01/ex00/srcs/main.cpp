/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:35:40 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/02/29 17:26:26 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <thread>

int main() 
{
	std::cout << G << "Zombie created on the stack called henk, class will be destroyed when main is finished: " << END << std::endl;
	Zombie zombie1("Henk");
	zombie1.announce();
	
	std::cout << G << "Zombie \"Harry\" created (heap) using function newZombie, pointer can be used outside of scope but has the be deleted manually: " << END << std::endl;
	Zombie *ptr = newZombie("Harry");
	ptr->announce();
	std::cout << R << "Zombie \"Harry\" will be destroyed manually" << END << std::endl;
	delete (ptr);
	
	std::cout << G << "Zombie created (stack) using randomChump called Barry, class will be destroyed as soon as the function is finished." << END << std::endl;
	randomChump("Barry");
	
	std::cout << R << "Zombie henk will be destroyed when main finishes " << END << std::endl;
	return (0);
}