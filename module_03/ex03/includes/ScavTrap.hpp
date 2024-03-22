/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:41:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/15 13:04:26 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class ScavTrap : virtual public ClapTrap {

	public:
	/* Constructors */
		ScavTrap( void );
		ScavTrap( std::string const NewName );
		ScavTrap( const ScavTrap &src );
	
	/* Destructors */
		~ScavTrap( void );
	
	/* Operator overide */
		ScavTrap &		operator=( const ScavTrap &rhs );

		void 			attack(const std::string& target);
		void 			guardGate();
			
	};

#endif