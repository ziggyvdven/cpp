/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:41:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/28 12:01:15 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class ClapTrap{
		
	protected:
		
		std::string 	_Name;
		unsigned int	_Hit;
		unsigned int	_Energy;
		unsigned int	_Attack;
		bool 			_isAlive( void ) const;
		bool 			_isAwake( void ) const;
	
	public:
						ClapTrap( void );
						ClapTrap( std::string const Name );
						ClapTrap( const ClapTrap &src );
						~ClapTrap( void );
		ClapTrap &		operator=( const ClapTrap &rhs );

		void 			attack(const std::string& target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);

		std::string 	getName( void ) const;
		unsigned int 	getHit( void ) const;
		unsigned int 	getEnergy( void ) const;
		unsigned int 	getAttack( void ) const;

			
	};

#endif