/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:46:51 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/15 12:52:46 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/**************************  CANONICAL FORM  **********************************/
/******************************************************************************/

/*DEFAULT CONSTRUCTOR/DESTRUCTOR **********************************************/

ScavTrap::ScavTrap( void ) : ClapTrap() {
	this->Name = "";
	this->Hit = 100;
	this->Energy = 50;
	this->Attack = 20; 
	std::cout << G << "ScavTrap Default constructor called" << END << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << R << "ScavTrap Destructor called" << END << std::endl;
}

/*DEFAULT COPY CONSTRUCTOR ****************************************************/

ScavTrap::ScavTrap( ScavTrap const & src ){
	std::cout << G << "(ScavTrap) Copy constructor called" << END << std::endl;
	*this = src;
}

/*COPY ASSIGMENTN OPERATOR OVERLOAD *******************************************/

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs){
	
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->Name = 	rhs.Name;
		this->Hit = 	rhs.Hit;
		this->Energy = rhs.Energy;
		this->Attack = rhs.Attack;
	}
	return (*this);
}

/******************************************************************************/
/******************************************************************************/

/*GETTERS & SETTERS************************************************************/


/*PARAMETRIC CONSTRUCTOR ******************************************************/

ScavTrap::ScavTrap(std::string const NewName) : ClapTrap( NewName ) {
	this->Hit = 100;
	this->Energy = 50;
	this->Attack = 20; 
	std::cout << G << "(ScavTrap) Parametric constructor called" << END << std::endl;
}

/*MEMBER FUNCTIONS ************************************************************/


	void 	ScavTrap::attack(const std::string& target){

		if (!this->isAwake())
			std::cout << "ClapTrap " << BOLD << this->Name << END << " cannot attack" << B << " (No energy) " << END << std::endl;
		if (!this->isAlive())
			std::cout << "ClapTrap " << BOLD << this->Name << END << " cannot attack" << R << " (Death) " << END << std::endl;
		if (isAwake() && isAlive())
		{
			this->Energy -= 1;
			std::cout << "ScavTrap " << BOLD << this->Name << END << " attacks " << target << ", causing " << Attack << " points of damage!" << std::endl;
		}
		return ;
	}

	void 	ScavTrap::guardGate(){
		std::cout << "ScavTrap " << BOLD << this->Name << END << " is now in gatekeeper mode!" << std::endl;
	}



