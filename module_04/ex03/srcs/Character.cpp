/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:37 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/22 20:05:32 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"

AMateria* g_floor[100];

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(): ICharacter(), name("")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	_materias[0] = "ice";
    _materias[1] = "cure";
	std::cout << G << "Character Default constructor called" << END << std::endl;
}

Character::Character( const Character & src ): ICharacter()
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	_materias[0] = "ice";
    _materias[1] = "cure";
	name = src.getName();
	for (int i = 0; i < S_INVENTORY; i++)
	{
		for (int j = 0; j < N_MATERIALS ; j++)
			if (src.inventory[i] != NULL && src.inventory[i]->getType() == this->_materias[j])
			{
				switch (j){
					case 0:
						(this->inventory[i] = new Ice());
						break;
					case 1:
						(this->inventory[i] = new Cure());
						break;
					default:
						std::cout << "Material does not exist" << std::endl;
						break;
				}
			}
	}
}

Character::Character(std::string const & newname): name(newname){
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	_materias[0] = "ice";
    _materias[1] = "cure";
	std::cout << G << "Character " << name << " Parametric constructor called" << END << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	std::cout << R << "Character " << name << " Destructor called" << END << std::endl;
	for (int i = 0; i < S_INVENTORY; i++)
	{
		if (inventory[i])
		{
			delete this->inventory[i];
			inventory[i] = NULL;
		}
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	std::cout << "Character Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->name = rhs.getName();
		for (int i = 0; i < S_INVENTORY; i++)
		{
			if (inventory[i])
			{
				delete this->inventory[i];
				inventory[i] = NULL;
			}
			for (int j = 0; j < N_MATERIALS ; j++)
				if (rhs.inventory[i]->getType() == this->_materias[j])
				{
					switch (j){
						case 0:
							(this->inventory[i] = new Ice());
							break;
						case 1:
							(this->inventory[i] = new Cure());
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

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	o << "Type is = " << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void 		Character::equip(AMateria* m){
	
	if (m)
	{
		for (int i = 0; i < S_INVENTORY; i++)
		{
			if (inventory[i] == NULL)
			{
				for (int j = 0; j < N_MATERIALS ; j++)
					if (m->getType() == this->_materias[j])
					{
						switch (j){
							case 0:
								(inventory[i] = new Ice());
								break;
							case 1:
								(inventory[i] = new Cure());
								break;
							default:
								std::cout << "Material does not exist" << std::endl;
								break;
						}
					}
				std::cout << name << " equiped " << m->getType() << " in inventory slot [" << i << "]." << std::endl;
				return;
			}
		}
		std::cout << name << " Cannot equip " << m->getType() << " [inventory full]." << std::endl;
	}
}

void Character::unequip(int idx){
	if (idx >= 0 && idx < S_INVENTORY && inventory[idx])
	{
		std::cout << name << " unequiped " << inventory[idx]->getType() << " in inventory slot [" << idx << "]." << std::endl;
		for(int i = 0; i < 100; i++)
		{
			if (!g_floor[i])
			{
				g_floor[i] = inventory[idx];
				break;
			}
		}
		inventory[idx] = NULL;
	}
	else
		std::cout << name << " failed to unequip slot [" << idx << "]."<< std::endl;;
}

void 			Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx < S_INVENTORY && inventory[idx])
		inventory[idx]->use(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Character::getName() const{
	return (this->name);
}


/* ************************************************************************** */