/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:35:33 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/21 19:27:19 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): Animal(), _brainptr( NULL ) {
	Animal::type = "Dog";
	this->_brainptr = new Brain();
	std::cout << G << "Dog Default constructor called" << END << std::endl;
}

Dog::Dog( const Dog & src ): Animal(), _brainptr(NULL) {
	std::cout << G << "Dog Copy constructor called" << END << std::endl;
	if (src._brainptr)
		this->_brainptr = new Brain(*src._brainptr);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog(){
	std::cout << R << "Dog Destructor called" << END << std::endl;
	if (this->_brainptr)
		delete this->_brainptr;
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
		delete _brainptr;
		_brainptr = NULL;
		if (rhs._brainptr)
			_brainptr = new Brain(*rhs._brainptr);
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

std::string Dog::getIdea(int i) const{
		if (i < 100 && i >= 0)
			return (this->_brainptr->getIdea(i));
		else 
			std::cout << "INDEX " << i << " exceeds boundries of _ideas[100]." << std::endl;
		return ("");
	}

void Dog::setIdea(int i, std::string idea) {
		if (i < 100 && i >= 0)
			this->_brainptr->setIdea(i, idea);
		else 
			std::cout << "INDEX " << i << " exceeds boundries of _ideas[100]." << std::endl;;
		return ;
	}

/* ************************************************************************** */