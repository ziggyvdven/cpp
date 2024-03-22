/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:46:51 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/15 13:49:05 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/**************************  CANONICAL FORM  **********************************/
/******************************************************************************/

/*DEFAULT CONSTRUCTOR/DESTRUCTOR **********************************************/

ClapTrap::ClapTrap( void ) : Name(""), Hit(10), Energy(10), Attack(0){
	std::cout << G << "Claptrap Default constructor called" << END << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << R << "Claptrap Destructor called" << END << std::endl;
}

/*DEFAULT COPY CONSTRUCTOR ****************************************************/

ClapTrap::ClapTrap( ClapTrap const & src ){
	std::cout << G << "Claptrap Copy constructor called" << END << std::endl;
	*this = src;
}

/*COPY ASSIGMENTN OPERATOR OVERLOAD *******************************************/

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs){
	
	std::cout << "(claptrap) Copy assignment operator called" << std::endl;
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

	std::string ClapTrap::getName() const{
		return (this->Name);
	}

	unsigned int ClapTrap::getHit() const{
		return (this->Hit);
	}

	unsigned int ClapTrap::getEnergy() const{
		return (this->Energy);
	}

	unsigned int ClapTrap::getAttack() const{
		return (this->Attack);
	}

/*PARAMETRIC CONSTRUCTOR ******************************************************/

ClapTrap::ClapTrap(std::string const NewName) : Name(NewName), Hit(10), Energy(10), Attack(0) {
	std::cout << G << "Claptrap Parametric constructor called" << END << std::endl;
}

/*MEMBER FUNCTIONS ************************************************************/

	bool ClapTrap::isAlive( void ) const{

		if (this->Hit > 0)
			return ( true );
		else
			return ( false );
	}

	bool ClapTrap::isAwake( void ) const{

		if (this->Energy > 0)
			return ( true );
		else
			return ( false );
	}

	void ClapTrap::attack(const std::string& target){

		if (!this->isAwake())
			std::cout << "ClapTrap " << BOLD << this->Name << END << " cannot attack." << B << " (No energy) " << END << std::endl;
		if (!this->isAlive())
			std::cout << "ClapTrap " << BOLD << this->Name << END << " cannot attack." << R << " (Death) " << END << std::endl;
		if (this->isAwake() && this->isAlive())
		{
			this->Energy -= 1;
			std::cout << "ClapTrap " << BOLD << this->Name << END << " attacks " << target << ", causing " << Attack << " points of damage!" << std::endl;
		}
		return ;
	}
	
	void ClapTrap::takeDamage(unsigned int amount){

		if (this->Hit >= amount)
			this->Hit -= amount;
		else
			this->Hit = 0;
		std::cout << "ClapTrap " << BOLD << this->Name << END << " got damaged for " << amount << " points!" << std::endl;
		return ;
	}

	void ClapTrap::beRepaired(unsigned int amount){

		if (!this->isAwake())
			std::cout << "ClapTrap " << BOLD << this->Name << END << " cannot be repaired" << B << " (No energy) " << END << std::endl;
		if (!this->isAlive())
			std::cout << "ClapTrap " << BOLD << this->Name << END << " cannot be repaired" << R << " (DEATH) " << END << std::endl;
		if (this->isAwake() && this->isAlive())
		{
			this->Hit += amount;
			this->Energy -= 1;
			std::cout << "ClapTrap " << BOLD << this->Name << END << " repairs itself for " << amount << " points!" << std::endl;
		}
		return ;
	}


