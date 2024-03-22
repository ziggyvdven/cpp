/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:35:33 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/21 20:29:09 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): Animal(), _brainptr( NULL ) {
	Animal::type = "Cat";
	this->_brainptr = new Brain();
	std::cout << G << "Cat Default constructor called" << END << std::endl;
}

Cat::Cat( const Cat & src ): Animal(), _brainptr(NULL) {
	std::cout << G << "Cat Copy constructor called" << END << std::endl;
	if (src._brainptr)
		this->_brainptr = new Brain(*src._brainptr);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat(){
	std::cout << R << "Cat Destructor called" << END << std::endl;
	if (this->_brainptr)
		delete this->_brainptr;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
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

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "Value = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void			Cat::makeSound( void ) const{
	std::cout << "ARSCHLOCH! i mean WOOF" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Cat::getType() const{
		return (this->type);
	}

std::string Cat::getIdea(int i) const{
		if (i < 100 && i >= 0)
			return (this->_brainptr->getIdea(i));
		else 
			std::cout << "INDEX " << i << " exceeds boundries of _ideas[100]." << std::endl;
		return ("");
	}

void Cat::setIdea(int i, std::string idea) {
		if (i < 100 && i >= 0)
			this->_brainptr->setIdea(i, idea);
		else 
			std::cout << "INDEX " << i << " exceeds boundries of _ideas[100]." << std::endl;;
		return ;
	}

/* ************************************************************************** */