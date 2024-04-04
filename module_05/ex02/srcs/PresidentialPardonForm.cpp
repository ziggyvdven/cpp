/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:30:35 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/04 17:57:49 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ): AForm(src.getName(), src.get_toSign(), src.get_toExec()){
	if (src.get_toSign() > 150 || src.get_toExec() > 150)
		throw GradeTooLowException();
	if (src.get_toSign() < 1 || src.get_toExec() < 1)
		throw GradeTooHighException();
	this->setSigned(src.getSigned());
	this->_target = src._target;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5){
	if (target.empty())
		throw StringCantBeEmpty();
	else 
		this->_target = target;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->setSigned(rhs.getSigned());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
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

const char* PresidentialPardonForm::StringCantBeEmpty::what() const throw(){
    return("STRING EMPTY");
};

bool				PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	
	if (&executor != nullptr){
		canExec(executor);
		std::cout << G << this->_target << " has been pardoned by Zaphod Beeblebrox. " << END << std::endl;
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

std::string					PresidentialPardonForm::getTarget() const{
	return (this->_target);
}




/* ************************************************************************** */