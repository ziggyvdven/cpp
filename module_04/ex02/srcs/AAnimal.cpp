/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:27:58 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/22 13:37:14 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal(): type("AAnimal"){
	std::cout << G << "AAnimal Default constructor called" << END << std::endl;
}

AAnimal::AAnimal( const AAnimal & src ){
	std::cout << G << "AAnimal Copy constructor called" << END << std::endl;
	*this = src;
}

AAnimal::AAnimal(std::string const type) : type(type) {
	std::cout << G << "AAnimal Parametric constructor called" << END << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal(){
	std::cout << R << "AAnimal Destructor called" << END << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &				AAnimal::operator=( AAnimal const & rhs )
{
	std::cout << "AAnimal Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AAnimal const & i )
{
	o << "Value = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void			AAnimal::makeSound( void ) const{
	std::cout << "ICH BIN EIN TIER!!!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AAnimal::getType() const{
		return (this->type);
	}

/* ************************************************************************** */