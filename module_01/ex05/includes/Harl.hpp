/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:30:50 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/07 13:58:07 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	HARL_HPP
# define	HARL_HPP

#include <string>
#include <iostream>

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	
	void (Harl::*_f[4])(void);
	std::string _flags[4];
	
public:
	Harl();
	~Harl();
	void complain( std::string level );
};

#endif