/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:46:51 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/13 17:36:06 by zvan-de-         ###   ########.fr       */
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

	unsigned int ClapTrap::getHitPoints() const{
		return (this->_Hit);
	}

/*PARAMETRIC CONSTRUCTOR ******************************************************/

ClapTrap::ClapTrap(std::string const Name) : _Name(Name), _Hit(10), _Energy(10), _Attack(0) {
	std::cout << "Parametric constructor called" << std::endl;
}

/*MEMBER FUNCTIONS ************************************************************/

	bool ClapTrap::alive( void ) const{
		
		if (this->)
	}


	void ClapTrap::attack(const std::string& target){

		if (this->Hit)
		this->_Energy -= 1;
		std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << _Attack << " points of damage!" << std::endl;
		return ;
	}
	
	void ClapTrap::takeDamage(unsigned int amount){

		this->_Hit -= amount;
		std::cout << "ClapTrap " << this->_Name << " got damaged for " << amount << " points!" << std::endl;
		return ;
	}

	void ClapTrap::beRepaired(unsigned int amount){

		this->_Hit += amount;
		this->_Energy -= 1;
		std::cout << "ClapTrap " << this->_Name << " repairs itself for " << amount << " points!" << std::endl;
		return ;
	}


