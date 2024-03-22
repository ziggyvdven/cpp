/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:27:58 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/20 14:28:02 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal(): type("animal"){
	std::cout << G << "Animal Default constructor called" << END << std::endl;
}

Animal::Animal( const Animal & src ){
	std::cout << G << "Animal Copy constructor called" << END << std::endl;
	*this = src;
}

Animal::Animal(std::string const type) : type(type) {
	std::cout << G << "Animal Parametric constructor called" << END << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal(){
	std::cout << R << "Animal Destructor called" << END << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << "Value = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void			Animal::makeSound( void ) const{
	std::cout << "ICH BIN EIN TIER!!!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType() const{
		return (this->type);
	}

/* ************************************************************************** */