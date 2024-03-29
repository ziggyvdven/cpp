/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:37 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/28 15:49:03 by zvan-de-         ###   ########.fr       */
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
	_materias[0] = "ice";
    _materias[1] = "cure";
}

MateriaSource::MateriaSource( const MateriaSource & src ): IMateriaSource()
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->memory[i] = NULL;
	_materias[0] = "ice";
    _materias[1] = "cure";
	for (int i = 0; i < S_MEMORY; i++)
	{
		for (int j = 0; j < N_MATERIALS ; j++)
			if (src.memory[i] != NULL && src.memory[i]->getType() == this->_materias[j])
			{
				switch (j){
					case 0:
						(this->memory[i] = new Ice());
						break;
					case 1:
						(this->memory[i] = new Cure());
						break;
					default:
						std::cout << "Material does not exist" << std::endl;
						break;
				}
			}
	}
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
		for (int i = 0; i < S_MEMORY; i++)
		{
			if (memory[i])
			{
				delete this->memory[i];
				memory[i] = NULL;
			}
			for (int j = 0; j < 2 ; j++)
				if (rhs.memory[i]->getType() == this->_materias[j])
				{
					switch (j){
						case 0:
							(this->memory[i] = new Ice());
							break;
						case 1:
							(this->memory[i] = new Cure());
							break;
						default:
            				std::cout << "Material does not exist" << std::endl;
							break;
					}
				}
		}
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
	delete m;
	std::cout << "MateriaSource did not learn " << m->getType() << std::endl;
}

AMateria* 		MateriaSource::createMateria(std::string const & type){
	 for ( int i = 0; i < 4; i++ )
        if ( memory[i] && memory[i]->getType() == type )
            return memory[i]->clone();
		std::cout << "MateriaSource can't create materia: " << type << std::endl;
    return NULL;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */