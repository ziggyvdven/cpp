/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/04 18:01:39 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

using std::cout;
using std::endl;
using std::exception;

int main()
{
	cout << BOLD << "-------------- BUREACRAT CREATION ------------" << END << std::endl;
	std::cout << "-------------- Testing for errors ------------" << std::endl;
	try {
		Bureaucrat worker("Squidward", 0);
	}
	catch (std::exception & e) {
		std::cout << "Could not instanciate Bureaucrat: [" << e.what() << "]" << std::endl;
	}
	
	try {
		Bureaucrat worker("Squidward", 151);
	}
	catch (std::exception & e) {
		std::cout << "Could not instanciate Bureaucrat: [" << e.what() << " ]" << std::endl;
	}
	
	cout << endl << "-------------- Creating 3 Workers ------------" << std::endl;
	Bureaucrat worker1 = Bureaucrat("Spongebob", 1);
	cout << worker1 << endl;
	Bureaucrat worker2 = Bureaucrat("Squidward", 50);
	cout << worker2 << endl;
	Bureaucrat worker3 = Bureaucrat("Patrick", 150);
	cout << worker3 << endl << endl;
	
	
	cout << BOLD << "-------------- FORM CREATION ------------" << END << std::endl;
	std::cout << "-------------- Testing for errors ------------" << std::endl;
	try {
		PresidentialPardonForm formerror("");
		cout << formerror << endl;
	}
	catch (std::exception & e) {	
		std::cout << R << "Could not create PresidentialPardonForm " << " [" << e.what() << "]" << END << std::endl;
	}
	
	// *NOT POSSIBLE BECAUSE AFORM IS AN ABSTRACT CLASS*
	// AForm formerror("");
	// cout << formerror << endl;
	
	cout << BOLD << "-------------- Creating Forms ------------" << END << std::endl;
	ShrubberyCreationForm form1("Bikini Bottom");
	cout << form1 << endl;
	RobotomyRequestForm form2("ROBO_PLANKTON");
	cout << form2 << endl;
	PresidentialPardonForm form3("PLANKTON");
	cout << form3 << endl << endl;
	ShrubberyCreationForm form4("CRABS");
	cout << form4 << endl << endl;
	
	cout << endl << BOLD << "------------ Testing signing form-------------" << END << endl;
	std::cout << worker3.getName() << " tries to sign: " << endl;
	worker3.signForm(form1);
	worker3.signForm(form2);
	worker3.signForm(form3);
	std::cout << worker2.getName() << " tries to sign: " << endl;
	worker2.signForm(form1);
	worker2.signForm(form2);
	worker2.signForm(form3);
	std::cout << worker1.getName() << " tries to sign: " << endl;
	worker1.signForm(form1);
	worker1.signForm(form2);
	worker1.signForm(form3);

	cout << endl << form1 << endl;
	cout << form2 << endl;
	cout << form3  << endl;
	cout << form4 << endl << endl;
	
	cout << endl << BOLD << "------------ EXECUTION TESTS-------------" << END << endl;
	std::cout << worker3.getName() << " tries to execute (USING bureaucrat.executeForm() ): " << endl;
	worker3.executeForm(form1);
	worker3.executeForm(form2);
	worker3.executeForm(form3);
	worker3.executeForm(form4);
	std::cout << worker2.getName() << " tries to execute (USING bureaucrat.executeForm() ): " << endl;
	worker2.executeForm(form1);
	worker2.executeForm(form2);
	worker2.executeForm(form3);
	worker2.executeForm(form4);
	std::cout << worker1.getName() << " tries to execute (USING form.execute() ): " << endl;
	try{
		form1.execute(worker1);
	}
	catch (std::exception & e) {
		std::cout << R << worker1.getName() << " could not execute " << form2.getName() << " because [" << e.what() << "]" << END << std::endl;
	}
	try{
		form2.execute(worker1);
	}
	catch (std::exception & e) {
		std::cout << R << worker1.getName() << " could not execute " << form2.getName() << " because [" << e.what() << "]" << END << std::endl;
	}
	try{
		form3.execute(worker1);
	}
	catch (std::exception & e) {
		std::cout << R << worker1.getName() << " could not execute " << form2.getName() << " because [" << e.what() << "]" << END << std::endl;
	}
	try{
		form4.execute(worker1);
	}
	catch (std::exception & e) {
		std::cout << R << worker1.getName() << " could not execute " << form2.getName() << " because [" << e.what() << "]" << END << std::endl;
	}
	return (0);
}
