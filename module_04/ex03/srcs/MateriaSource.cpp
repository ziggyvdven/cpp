/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:37 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/22 20:31:38 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource(): IMateriaSource()
{
	std::cout << G << "Cure Default constructor called" << END << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource & src ): IMateriaSource()
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	std::cout << R << "MateriaSource Destructor called" << END << std::endl;
	for (int i = 0; i < 4; i++)
        if (memory[i])
            delete memory[i];
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void 			MateriaSource::learnMateria(AMateria* m){
	for (int i = 0; i < 4; i++)
	{
		if (memory[i] == NULL)
		{
			memory[i] = m;
			std::cout << "MateriaSource learned " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource did not learn " << m->getType() << std::endl;
}

AMateria* 		MateriaSource::createMateria(std::string const & type){
	 for ( int i = 0; i < 4; i++ )
        if ( memory[i] && memory[i]->getType() == type )
            return memory[i]->clone();
    return NULL;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */