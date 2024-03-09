/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:35:40 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/02/29 17:35:03 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"
#include <thread>

int main() 
{
	std::cout << G << "Zombie horde!! Created on the heap it will have to be be deleted manually" << END << std::endl;
	Zombie* ptr = zombieHorde( 10, "Olivier" );
	delete[] ptr;
	return (0);
}