/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:41:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/15 14:57:10 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class DiamondTrap :  public ScavTrap, public FragTrap {

	private:
		std::string			Name;
		
	public:
	/* Constructors */
		DiamondTrap( void );
		DiamondTrap( std::string const NewName );
		DiamondTrap( const DiamondTrap &src );
	
	/* Destructors */
		~DiamondTrap( void );
	
	/* Operator overide */
		DiamondTrap &		operator=( const DiamondTrap &rhs );

		std::string 		getName( void ) const;
		void 				whoAmI();

		
		
	};

#endif