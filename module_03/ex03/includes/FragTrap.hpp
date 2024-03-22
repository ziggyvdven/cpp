/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:41:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/15 13:04:21 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class FragTrap : virtual public ClapTrap {

	public:
	/* Constructors */
		FragTrap( void );
		FragTrap( std::string const NewName );
		FragTrap( const FragTrap &src );
	
	/* Destructors */
		~FragTrap( void );
	
	/* Operator overide */
		FragTrap &		operator=( const FragTrap &rhs );

		void 			highFivesGuys(void);


	};

#endif