/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:46:51 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/14 13:14:01 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/**************************  CANONICAL FORM  **********************************/
/******************************************************************************/

/*DEFAULT CONSTRUCTOR/DESTRUCTOR **********************************************/

ClapTrap::ClapTrap( void ) : _Name(""), _Hit(10), _Energy(10), _Attack(0){
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}

/*DEFAULT COPY CONSTRUCTOR ****************************************************/

ClapTrap::ClapTrap( ClapTrap const & src ){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*COPY ASSIGMENTN OPERATOR OVERLOAD *******************************************/

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs){
	
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_Name = 	rhs._Name;
		this->_Hit = 	rhs._Hit;
		this->_Energy = rhs._Energy;
		this->_Attack = rhs._Attack;
	}
	return (*this);
}

/******************************************************************************/
/******************************************************************************/

/*GETTERS & SETTERS************************************************************/

	std::string ClapTrap::getName() const{
		return (this->_Name);
	}

	unsigned int ClapTrap::getHit() const{
		return (this->_Hit);
	}

	unsigned int ClapTrap::getEnergy() const{
		return (this->_Energy);
	}

	unsigned int ClapTrap::getAttack() const{
		return (this->_Attack);
	}

/*PARAMETRIC CONSTRUCTOR ******************************************************/

ClapTrap::ClapTrap(std::string const Name) : _Name(Name), _Hit(10), _Energy(10), _Attack(0) {
	std::cout << "Parametric constructor called" << std::endl;
}

/*MEMBER FUNCTIONS ************************************************************/

	bool ClapTrap::isAlive( void ) const{

		if (this->_Hit > 0)
			return ( true );
		else
			return ( false );
	}

	bool ClapTrap::isAwake( void ) const{

		if (this->_Energy > 0)
			return ( true );
		else
			return ( false );
	}

	void ClapTrap::attack(const std::string& target){

		if (!this->isAwake())
			std::cout << "ClapTrap " << BOLD << this->_Name << END << " cannot attack" << B << " (No energy) " << END << std::endl;
		if (!this->isAlive())
			std::cout << "ClapTrap " << BOLD << this->_Name << END << " cannot attack" << R << " (Death) " << END << std::endl;
		if (this->isAwake() && this->isAlive())
		{
			this->_Energy -= 1;
			std::cout << "ClapTrap " << BOLD << this->_Name << END << " attacks " << target << ", causing " << _Attack << " points of damage!" << std::endl;
		}
		return ;
	}
	
	void ClapTrap::takeDamage(unsigned int amount){

		if (this->_Hit >= amount)
			this->_Hit -= amount;
		else
			this->_Hit = 0;
		std::cout << "ClapTrap " << BOLD << this->_Name << END << " got damaged for " << amount << " points!" << std::endl;
		return ;
	}

	void ClapTrap::beRepaired(unsigned int amount){

		if (!this->isAwake())
			std::cout << "ClapTrap " << BOLD << this->_Name << END << " cannot be repaired" << B << " (No energy) " << END << std::endl;
		if (!this->isAlive())
			std::cout << "ClapTrap " << BOLD << this->_Name << END << " cannot be repaired" << R << " (DEATH) " << END << std::endl;
		if (this->isAwake() && this->isAlive())
		{
			this->_Hit += amount;
			this->_Energy -= 1;
			std::cout << "ClapTrap " << BOLD << this->_Name << END << " repairs itself for " << amount << " points!" << std::endl;
		}
		return ;
	}


