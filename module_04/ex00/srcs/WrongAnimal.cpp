/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:27:58 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/20 16:53:18 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal(): type("Wronganimal"){
	std::cout << G << "WrongAnimal Default constructor called" << END << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src ){
	std::cout << G << "WrongAnimal Copy constructor called" << END << std::endl;
	*this = src;
}

WrongAnimal::WrongAnimal(std::string const type) : type(type) {
	std::cout << G << "WrongAnimal Parametric constructor called" << END << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal(){
	std::cout << R << "WrongAnimal Destructor called" << END << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &			WrongAnimal::operator=( WrongAnimal const & rhs )
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i )
{
	o << "Value = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void			WrongAnimal::makeSound( void ) const{
	std::cout << "ICH BIN EIN TIER!!!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongAnimal::getType() const{
		return (this->type);
	}

/* ************************************************************************** */