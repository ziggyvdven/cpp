/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:35:33 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/20 14:47:33 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): Animal() {
	Animal::type = "Cat";
	std::cout << G << "Cat Default constructor called" << END << std::endl;
}

Cat::Cat( const Cat & src ){
	std::cout << G << "Cat Copy constructor called" << END << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat(){
	std::cout << R << "Cat Destructor called" << END << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		this->type = rhs.type;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "Value = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void			Cat::makeSound( void ) const{
	std::cout << "SWEINHUND! i mean MEOW" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Cat::getType() const{
		return (this->type);
	}

/* ************************************************************************** */