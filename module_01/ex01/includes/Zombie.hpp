/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:34:06 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/01/18 15:34:33 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cstring>

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class Zombie 
{
  private:
	std::string _name;
	
  public:
  	Zombie(); 
	~Zombie(void);
	void setName(std::string name);
	void announce(void);
};

Zombie* newZombie(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif