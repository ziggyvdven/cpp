/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:37 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/05 13:55:44 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	std::cout << G << "Intern Default constructor called" << END << std::endl;
	_forms[0] = "shrubbery creation";
    _forms[1] = "robotomy request";
	_forms[2] = "presidential pardon";
}

Intern::Intern( const Intern & src )
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	std::cout << R << "Intern Destructor called" << END << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	std::cout << "Intern Copy assignment operator called" << std::endl;
	for (int i = 0; i < N_FORMS; i++)
		this->_forms[i] = rhs._forms[i];
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


AForm* 			Intern::makeForm(std::string const form, std::string const target){
	 
 
	for (int i = 0; i <  N_FORMS ; i++)
				if (this->_forms[i] == form)
				{
					switch (i){
						case 0:
							std::cout << "Intern creates " << _forms[i] << std::endl;
							return (new ShrubberyCreationForm(target));
							break;
						case 1:
							std::cout << "Intern creates " << _forms[i] << std::endl;
							return (new RobotomyRequestForm(target));
							break;
						case 2:
							std::cout << "Intern creates " << _forms[i] << std::endl;
							return (new PresidentialPardonForm(target));
							break;
						default:
            				std::cout << "Form does not exist" << std::endl;
							break;
					}
				}
	std::cout << "Intern can't create form: " << form << std::endl;
    return NULL;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */