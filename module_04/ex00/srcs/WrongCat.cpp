/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:35:33 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/20 16:43:53 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat(): WrongAnimal() {
	WrongAnimal::type = "WrongCat";
	std::cout << G << "WrongCat Default constructor called" << END << std::endl;
}

WrongCat::WrongCat( const WrongCat & src ){
	std::cout << G << "WrongCat Copy constructor called" << END << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat(){
	std::cout << R << "WrongCat Destructor called" << END << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		this->type = rhs.type;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongCat const & i )
{
	o << "Value = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void			WrongCat::makeSound( void ) const{
	std::cout << "SWEINHUND! i mean MEOW" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongCat::getType() const{
		return (this->type);
	}

/* ************************************************************************** */