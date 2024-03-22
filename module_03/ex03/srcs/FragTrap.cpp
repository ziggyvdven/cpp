/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:46:51 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/15 14:26:17 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

/**************************  CANONICAL FORM  **********************************/
/******************************************************************************/

/*DEFAULT CONSTRUCTOR/DESTRUCTOR **********************************************/

FragTrap::FragTrap( void ) : ClapTrap() {
	this->Name = "";
	this->Hit = 100;
	this->Energy = 100;
	this->Attack = 30; 
	std::cout << G << "FragTrap Default constructor called" << END << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << R << "FragTrap Destructor called" << END << std::endl;
}

/*DEFAULT COPY CONSTRUCTOR ****************************************************/

FragTrap::FragTrap( FragTrap const & src ){
	std::cout << G << "(FragTrap) Copy constructor called" << END << std::endl;
	*this = src;
}

/*COPY ASSIGMENTN OPERATOR OVERLOAD *******************************************/

FragTrap & FragTrap::operator=( FragTrap const & rhs){
	
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->Name = 	rhs.Name;
		this->Hit = 	rhs.Hit;
		this->Energy = 	rhs.Energy;
		this->Attack = 	rhs.Attack;
	}
	return (*this);
}

/******************************************************************************/
/******************************************************************************/

/*GETTERS & SETTERS************************************************************/


/*PARAMETRIC CONSTRUCTOR ******************************************************/

FragTrap::FragTrap(std::string const NewName) : ClapTrap( NewName ) {
	this->Hit = 100;
	this->Energy = 100;
	this->Attack = 30; 
	std::cout << G << "(FragTrap) Parametric constructor called" << END << std::endl;
}

/*MEMBER FUNCTIONS ************************************************************/

void FragTrap::highFivesGuys( void ){
		if (!this->isAwake())
			std::cout << "FragTrap " << BOLD << this->Name << END << " cannot high-five." << B << " (No energy) " << END << std::endl;
		if (!this->isAlive())
			std::cout << "FragTrap " << BOLD << this->Name << END << " cannot high-five." << R << " (Death) " << END << std::endl;
		if (isAwake() && isAlive())
		{
			this->Energy -= 1;
			std::cout << "FragTrap " << BOLD << this->Name << END << " asks: can I get a left-handed HIGH-FIVE! " << std::endl;
		}
		return ;	
}



