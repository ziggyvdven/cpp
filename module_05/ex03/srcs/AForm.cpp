/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:04:04 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/03 15:42:03 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
# include <iomanip>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(): _name(""), _signed(false), _toSign(150), _toExec(0){
}

AForm::AForm( const AForm & src ): _name(src._name), _toSign(src._toSign), _toExec(src._toExec){
	if (src._toSign > 150 || src._toExec > 150)
		throw GradeTooLowException();
	if (src._toSign < 1 || src._toExec < 1)
		throw GradeTooHighException();
	*this = src;
}

AForm::AForm(std::string name, unsigned int toSign, unsigned int toExec): _name(name), _signed(false), _toSign(toSign), _toExec(toExec){

	if (toSign > 150 || toExec > 150)
		throw GradeTooLowException();
	if (toSign < 1 || toExec < 1)
		throw GradeTooHighException();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs._signed;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << BOLD << "      NAME|    SIGNED|    toSIGN|    toEXEC" << END << std::endl;
	o << std::right << std::setw(10) << i.getName() << '|';
	o << std::right << std::setw(10) << i.getSigned() << '|';
	o << std::right << std::setw(10) << i.get_toSign() << '|';
	o << std::right << std::setw(10) << i.get_toExec();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char* AForm::GradeTooLowException::what() const throw(){
    return("GRADE TOO LOW");
};

const char* AForm::GradeTooHighException::what() const throw(){
     return("GRADE TOO HIGH");
};

const char* AForm::FormAlreadySigned::what() const throw(){
     return("ALREADY SIGNED");
};

const char* AForm::FormNotSigned::what() const throw(){
     return("NOT SIGNED");
};

bool				AForm::beSigned(const Bureaucrat& worker){
	if (_signed)
		throw FormAlreadySigned();
	else if (_toSign < worker.getGrade())
		throw GradeTooLowException();
	else
	{
		_signed = true;
		return (true);
	}
	return false;
}

bool				AForm::canExec(const Bureaucrat& executor) const{
	if (!getSigned())
		throw FormNotSigned();
	else if (get_toExec() < executor.getGrade())
		throw GradeTooLowException();
	return true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string			AForm::getName() const{
	return (this->_name);
}

unsigned int		AForm::get_toSign() const{
	return (this->_toSign);
}

unsigned int		AForm::get_toExec() const{
	return (this->_toExec);
}

bool				AForm::getSigned() const{
	return (this->_signed);
}

void				AForm::setSigned(bool const sign){
	this->_signed = sign;
	return ;
}

/* ************************************************************************** */