/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:04:04 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/29 18:25:08 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
# include <iomanip>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(): _name(""), _signed(false), _toSign(150), _toExec(0){
}

Form::Form( const Form & src ): _name(src._name), _toSign(src._toSign), _toExec(src._toExec){
	if (src._toSign > 150 || src._toExec > 150)
		throw GradeTooLowException();
	if (src._toSign < 1 || src._toExec < 1)
		throw GradeTooHighException();
	*this = src;
}

Form::Form(std::string name, unsigned int toSign, unsigned int toExec): _name(name), _signed(false), _toSign(toSign), _toExec(toExec){

	if (toSign > 150 || toExec > 150)
		throw GradeTooLowException();
	if (toSign < 1 || toExec < 1)
		throw GradeTooHighException();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs._signed;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
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

const char* Form::GradeTooLowException::what() const throw(){
    return("GRADE TOO LOW");
};

const char* Form::GradeTooHighException::what() const throw(){
     return("GRADE TOO HIGH");
};

const char* Form::FormAlreadySigned::what() const throw(){
     return("ALREADY SIGNED");
};

bool				Form::beSigned(const Bureaucrat& worker){
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

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string			Form::getName() const{
	return (this->_name);
}

unsigned int		Form::get_toSign() const{
	return (this->_toSign);
}

unsigned int		Form::get_toExec() const{
	return (this->_toExec);
}

bool				Form::getSigned() const{
	return (this->_signed);
}

/* ************************************************************************** */