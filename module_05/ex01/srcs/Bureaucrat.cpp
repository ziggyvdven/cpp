/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:06:43 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/29 18:29:18 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
# include <iomanip>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(): _name(""), _grade(150){
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ){
	*this = src;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name){

	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	else 
		this->_grade = grade;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << BOLD << "      NAME|     GRADE|" << END << std::endl;
	o << std::right << std::setw(10) << i.getName() << '|';
	o << std::right << std::setw(10) << i.getGrade() << '|';
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Bureaucrat::incrementGrade(){
    if (_grade > 1)
            _grade--;
    else
        throw GradeTooHighException();
	
}

void				Bureaucrat::decrementGrade(){
	if (_grade < 150)
            _grade++;
    else
        throw GradeTooLowException();
	
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return("GRADE TOO LOW");
};

const char* Bureaucrat::GradeTooHighException::what() const throw(){
     return("GRADE TOO HIGH");
};

void				Bureaucrat::signForm(Form& form) const{
	try {
		if (form.beSigned(*this))
			std::cout << G << _name << " signed Form " << form.getName() << END << std::endl;
	}
	catch (std::exception & e) {
		std::cout << R << _name << " could not sign Form " << form.getName() << " [" << e.what() << "]" << END << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string			Bureaucrat::getName() const{
	return (this->_name);
}

unsigned int		Bureaucrat::getGrade() const{
	return (this->_grade);
}


/* ************************************************************************** */