/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:03:59 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/29 18:32:52 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class Form
{

	public:

		Form( Form const & src );
		Form(std::string name, unsigned int toSign, unsigned int toExec);
		~Form();

		Form &				operator=( Form const & rhs );

		std::string			getName() const;
		unsigned int		get_toSign() const;
		unsigned int		get_toExec() const;
		bool				getSigned() const;
		bool				beSigned(Bureaucrat const & worker);

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

	
	private:
		
		Form();
		const std::string 	_name;
		bool  				_signed;
		const unsigned int	_toSign;
		const unsigned int	_toExec;
		

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */