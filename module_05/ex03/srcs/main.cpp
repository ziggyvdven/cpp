/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/04 18:42:23 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"


using std::cout;
using std::endl;
using std::exception;

int main()
{
	Bureaucrat worker1 = Bureaucrat("Spongebob", 1);
    Intern  someRandomIntern;
    AForm*   rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	worker1.signForm(*rrf);
	worker1.executeForm(*rrf);
	

	AForm*   ptr2;
	ptr2 = someRandomIntern.makeForm("shrubbery creation", "Bender2");
	rrf = ptr2;
	worker1.signForm(*rrf);
	// worker1.executeForm(*rrf);
	worker1.executeForm(*ptr2);
	Intern  someRandomIntern2(someRandomIntern);
	
	return (0);
}
