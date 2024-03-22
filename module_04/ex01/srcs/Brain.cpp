/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:27:58 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/21 19:11:57 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() {
	std::cout << G << "Brain Default constructor called" << END << std::endl;
}

Brain::Brain( const Brain & src ){
	std::cout << G << "Brain Copy constructor called" << END << std::endl;
	*this = src;
}

// Brain::Brain(std::string const type) : {
// 	std::cout << G << "Brain Parametric constructor called" << END << std::endl;
// }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain(){
	std::cout << R << "Brain Destructor called" << END << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Brain::getIdea(const int i) const{
		return (this->_ideas[i]);
	}

void Brain::setIdea(const int i, std::string idea) {
		if (i < 100)
			this->_ideas[i] = idea;
		return ;
	}

/* ************************************************************************** */