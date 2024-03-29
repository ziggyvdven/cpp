/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:04:04 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/28 19:46:05 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(): _name(""), _signed(150), _toSign(150), _toExec(0){
}

Form::Form( const Form & src ): _toSign(src._toSign), _toExec(src._toExec){
	*this = src;
}

Form::Form(std::string name, unsigned int toSign, unsigned int toExec): _name(name), _signed(0), _toSign(toSign), _toExec(toExec){

	if (toSign > 150 || toExec > 150)
		throw GradeTooLowException();
	if (toSign > 150 || toExec > 150)
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
	o << "Value = " << i.getName();
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

bool		Form::getSigned() const{
	return (this->_signed);
}

/* ************************************************************************** */