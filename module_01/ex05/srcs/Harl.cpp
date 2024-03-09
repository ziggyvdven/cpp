/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:35:12 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/07 13:57:00 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Harl.hpp"
# include <iomanip>

Harl::Harl( void )
{	
	_flags[0] = "DEBUG";
    _flags[1] = "INFO";
    _flags[2] = "WARNING";
    _flags[3] = "ERROR";
	_f[0] = &Harl::debug;
	_f[1] = &Harl::info;
	_f[2] = &Harl::warning;
	_f[3] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::debug( void ){
	std::cout << BOLD << "[DEBUG]     " << END << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ){
	std::cout << BOLD << "[INFO]      " << END << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ){
	std::cout << BOLD << "[WARNING]   " << END << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ){
	std::cout << BOLD << "[ERROR]     " << END << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	if (level.empty())
		return;
	for (int i = 0; i <= 4; i++)
		if (level == this->_flags[i])
		{
			(this->*_f[i])();
				return;
		}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
