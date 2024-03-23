/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWrongAnimal.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:27:58 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/22 13:35:34 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AWrongAnimal::AWrongAnimal(): type("AWrongAnimal"){
	std::cout << G << "AWrongAnimal Default constructor called" << END << std::endl;
}

AWrongAnimal::AWrongAnimal( const AWrongAnimal & src ){
	std::cout << G << "AWrongAnimal Copy constructor called" << END << std::endl;
	*this = src;
}

AWrongAnimal::AWrongAnimal(std::string const type) : type(type) {
	std::cout << G << "AWrongAnimal Parametric constructor called" << END << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AWrongAnimal::~AWrongAnimal(){
	std::cout << R << "AWrongAnimal Destructor called" << END << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AWrongAnimal &			AWrongAnimal::operator=( AWrongAnimal const & rhs )
{
	std::cout << "AWrongAnimal Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AWrongAnimal const & i )
{
	o << "Value = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void			AWrongAnimal::makeSound( void ) const{
	std::cout << "ICH BIN EIN TIER!!!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AWrongAnimal::getType() const{
		return (this->type);
	}

/* ************************************************************************** */