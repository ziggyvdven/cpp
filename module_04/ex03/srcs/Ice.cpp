/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:37 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/28 15:32:56 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice(): AMateria("ice")
{
	std::cout << G << "Ice Default constructor called" << END << std::endl;
}

Ice::Ice( const Ice & src )
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
	std::cout << R << "Ice destructor called" << END << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &				Ice::operator=( Ice const & rhs )
{
	if ( this->type != rhs.getType() )
	{
		this->type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Ice const & i )
{
	o << "Type is = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Ice* Ice::clone() const{
	
	return (new Ice(*this));
}

void Ice::use(ICharacter& target){
	if (!target.getName().empty())
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string const & Ice::getType() const{
	return (this->type);
}

/* ************************************************************************** */