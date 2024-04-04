/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:04:04 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/29 18:25:08 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ): AForm(src.getName(), src.get_toSign(), src.get_toExec()){
	if (src.get_toSign() > 150 || src.get_toExec() > 150)
		throw GradeTooLowException();
	if (src.get_toSign() < 1 || src.get_toExec() < 1)
		throw GradeTooHighException();
	this->setSigned(src.getSigned());
	this->_target = src._target;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137){
	if (target.empty())
		throw StringCantBeEmpty();
	else 
		this->_target = target;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->setSigned(rhs.getSigned());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
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

const char* ShrubberyCreationForm::StringCantBeEmpty::what() const throw(){
    return("STRING EMPTY");
};

bool				ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	
	if (&executor != nullptr){
		canExec(executor);
		std::ofstream 	_ofs(_target + "_shrubbery");
		if (!_ofs.is_open())
		{
			std::cout << "Error opening file for writing!" << std::endl;
			return false;
		}
		_ofs << "               ,@@@@@@@," << std::endl;
	 	_ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    	_ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
   		_ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
   		_ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
   		_ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
   		_ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
   		_ofs << "       |o|        | |         | |" << std::endl;
		_ofs << "       |.|        | |         | |" << std::endl;
		_ofs <<"jgs  \\/ ._\\//_/__/  ,\\_//___\\/.  \\_//__/_"   << std::endl;
		_ofs.close();
	}
	else
	{ 
		std::cerr << "Error: Parameter is a null reference." << std::endl;
		return false;
	}
	return true;

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string					ShrubberyCreationForm::getTarget() const{
	return (this->_target);
}




/* ************************************************************************** */