/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:04:27 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/01/18 17:02:59 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombiehorde = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
		zombiehorde[i].setName(name);
		std::cout << "Zombie #" << i + 1 << " ";
		zombiehorde[i].announce();
	}
	return (zombiehorde);	
}
