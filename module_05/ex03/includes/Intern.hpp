/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:43 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/05 13:58:19 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "../includes/ShrubberyCreationForm.hpp"

#ifndef INTERN_HPP
# define INTERN_HPP

/* Default number of forms */
# ifndef	N_FORMS
#  define	N_FORMS		3
# endif


class Intern
{
	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &			operator=( Intern const & rhs );
		AForm* 				makeForm(std::string const form, std::string const target);
	
	private:
		std::string 		_forms[N_FORMS];
};


#endif /* ************************************************** Intern_H */