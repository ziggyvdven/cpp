/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:46:51 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/15 15:02:28 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

/**************************  CANONICAL FORM  **********************************/
/******************************************************************************/

/*DEFAULT CONSTRUCTOR/DESTRUCTOR **********************************************/

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap() {
	ClapTrap::Name = "Random Name";
	this->Name = "";
	this->Hit = 	FragTrap::getHit();
	this->Energy = 	ScavTrap::getEnergy();
	this->Attack = 	FragTrap::getAttack(); 
	std::cout << G << "DiamondTrap Default constructor called" << END << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << R << "DiamondTrap Destructor called" << END << std::endl;
}

/*DEFAULT COPY CONSTRUCTOR ****************************************************/

DiamondTrap::DiamondTrap( DiamondTrap const & src ){
	std::cout << G << "(DiamondTrap) Copy constructor called" << END << std::endl;
	*this = src;
}

/*COPY ASSIGMENTN OPERATOR OVERLOAD *******************************************/

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & rhs){
	
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
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

std::string 	DiamondTrap::getName( void ) const{
	return (DiamondTrap::Name);
}

/*PARAMETRIC CONSTRUCTOR ******************************************************/

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {
	this->Name = name;
	this->Hit = FragTrap::Hit;
	this->Energy = ScavTrap::Energy;
	this->Attack = FragTrap::Attack; 
	std::cout << G << "(DiamondTrap) Parametric constructor called" << END << std::endl;
}

/*MEMBER FUNCTIONS ************************************************************/

void 				DiamondTrap::whoAmI(){
	std::cout << "I am " << BOLD << this->Name << END << " and ClapTraps name is: " << BOLD << ClapTrap::Name << END << std::endl;
}



