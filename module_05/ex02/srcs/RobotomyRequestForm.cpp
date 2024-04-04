/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:30:35 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/04 17:58:58 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ): AForm(src.getName(), src.get_toSign(), src.get_toExec()){
	if (src.get_toSign() > 150 || src.get_toExec() > 150)
		throw GradeTooLowException();
	if (src.get_toSign() < 1 || src.get_toExec() < 1)
		throw GradeTooHighException();
	this->setSigned(src.getSigned());
	this->_target = src._target;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45){
	if (target.empty())
		throw StringCantBeEmpty();
	else 
		this->_target = target;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->setSigned(rhs.getSigned());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << BOLD << "                  NAME|    SIGNED|    toSIGN|    toEXEC|    TARGET" << END << std::endl;
	o << std::left << std::setw(22) << i.getName() << '|';
	o << std::right << std::setw(10) << i.getSigned() << '|';
	o << std::right << std::setw(10) << i.get_toSign() << '|';
	o << std::right << std::setw(10) << i.get_toExec() << '|';
	o << std::left << std::setw(10) << i.getTarget();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char* RobotomyRequestForm::StringCantBeEmpty::what() const throw(){
    return("STRING EMPTY");
};

bool				RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	
	if (&executor != nullptr){
		canExec(executor);
		std::cout << BOLD << "*DRILLING NOISES* BRRR BRRR " << END << std::endl;
		
		srand((unsigned) time(NULL));
		int random = rand() % 2;
		sleep(1);
		if (random == 1)
			std::cout << G << this->_target << " has been robotomized succesfully! " << END << std::endl;
		else
			std::cout << R << "Robotomy of " << this->_target << " has failed." << END << std::endl;
		return true;
	}
	else
	{ 
		std::cerr << "Error: Parameter is a null reference." << std::endl;
		return false;
	}

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string					RobotomyRequestForm::getTarget() const{
	return (this->_target);
}




/* ************************************************************************** */