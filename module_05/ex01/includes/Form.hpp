/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:03:59 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/28 19:44:50 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Form
{

	public:

		Form();
		Form( Form const & src );
		Form(std::string name, unsigned int toSign, unsigned int toExec);
		~Form();

		Form &				operator=( Form const & rhs );

		std::string			getName() const;
		unsigned int		get_toSign() const;
		unsigned int		get_toExec() const;
		bool				getSigned() const;

		class GradeTooLowException : public std::exception{
			public:
				virtual const char*what() const throw();	
		};

		class GradeTooHighException : public std::exception{
			public:
				virtual const char*what() const throw();
		};

	private:
		
		const std::string 	_name;
		bool  				_signed;
		const unsigned int	_toSign;
		const unsigned int	_toExec;
		

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */