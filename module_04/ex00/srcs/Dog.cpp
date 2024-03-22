/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:35:33 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/20 14:47:39 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): Animal() {
	Animal::type = "Dog";
	std::cout << G << "Dog Default constructor called" << END << std::endl;
}

Dog::Dog( const Dog & src ){
	std::cout << G << "Dog Copy constructor called" << END << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog(){
	std::cout << R << "Dog Destructor called" << END << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << "Value = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void			Dog::makeSound( void ) const{
	std::cout << "ARSCHLOCH! i mean WOOF" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Dog::getType() const{
		return (this->type);
	}

/* ************************************************************************** */