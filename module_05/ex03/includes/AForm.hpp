/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:03:59 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/04 15:11:28 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <unistd.h>
# include <fstream>

# include "Bureaucrat.hpp"

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class AForm
{

	public:

		AForm( AForm const & src );
		AForm(std::string name, unsigned int toSign, unsigned int toExec);
		virtual ~AForm();

		AForm &					operator=( AForm const & rhs );

		std::string				getName() const;
		unsigned int			get_toSign() const;
		unsigned int			get_toExec() const;
		bool					getSigned() const;
		bool					beSigned(Bureaucrat const & worker);
		virtual bool			execute(Bureaucrat const & executor) const = 0;
		

		class GradeTooLowException : public std::exception{
			public:
				virtual const char*what() const throw();	
		};

		class GradeTooHighException : public std::exception{
			public:
				virtual const char*what() const throw();
		};

		class FormAlreadySigned : public std::exception{
			public:
				virtual const char*what() const throw();
		};

		class FormNotSigned : public std::exception{
			public:
				virtual const char*what() const throw();
		};

	
	protected:

		void					setSigned(bool const sign);
		bool					canExec(Bureaucrat const & executor) const;
		AForm();
	
	private:
		
		const std::string 	_name;
		bool  				_signed;
		const unsigned int	_toSign;
		const unsigned int	_toExec;
		

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* *********************************************************** AFORM_H */