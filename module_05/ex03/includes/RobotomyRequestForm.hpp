/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:03:59 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/29 18:32:52 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class RobotomyRequestForm : public AForm
{

	public:

		RobotomyRequestForm( RobotomyRequestForm const & src );
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		std::string					getTarget() const;
		virtual bool				execute(Bureaucrat const & executor) const;

		class StringCantBeEmpty : public std::exception{
			public:
				virtual const char*what() const throw();
		};

	
	private:
		std::string		_target;
		RobotomyRequestForm();
		
};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ************************************************************ FORM_H */