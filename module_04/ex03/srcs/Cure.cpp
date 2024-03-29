/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:37 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/28 15:33:17 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure(): AMateria("cure")
{
	std::cout << G << "Cure Default constructor called" << END << std::endl;
}

Cure::Cure( const Cure & src )
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	std::cout << R << "Cure destructor called" << END << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &				Cure::operator=( Cure const & rhs )
{
	if ( this->type != rhs.getType() )
	{
		this->type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cure const & i )
{
	o << "Type is = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Cure* Cure::clone() const{
	
	return (new Cure(*this));
}

void Cure::use(ICharacter& target){
	if (!target.getName().empty())
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string const & Cure::getType() const{
	return (this->type);
}

/* ************************************************************************** */