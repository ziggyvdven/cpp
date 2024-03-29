/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/29 18:45:46 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

using std::cout;
using std::endl;
using std::exception;

int main()
{
	cout << BOLD << "-------------- Testing for errors ------------" << END << std::endl;
	try {
		cout << "Creating Form 328-A , toSign[0], toExec[0]." << endl;
		Form form1("328-A", 0, 0);
	}
	catch (exception & e) {
		cout << R << "Could not instanciate Form 328-A: [" << e.what() << "]" << END << endl;
	}
	cout << endl;
	try {
		cout << "Creating Form 328-B , toSign[151], toExec[1]." << endl;
		Form form2("328-B", 151, 1);
	}
	catch (exception & e) {
		cout << R << "Could not instanciate Form 328-A: [" << e.what() << " ]" << END << endl;
	}
	cout << endl;
	try {
		cout << "Creating Form 328-C , toSign[150], toExec[1]." << endl;
		Form form3("328-C", 150, 1);
		cout << form3 << endl;
		
		cout << "Copying Form 328-C [COPY CONSTRUCTOR]" << endl;
		Form form4(form3);
		cout << form4 << endl;
	}
	catch (exception & e) {
		cout << "Could not instanciate Form: [" << e.what() << " ]" << endl;
	}

	
	cout << endl << BOLD << "------------ Testing signing form-------------" << END << endl;
	cout << "Creating Bureaucrat:" << endl;
	Bureaucrat worker1("Squidward", 50);
	cout << worker1 << endl;
	cout << endl << "Creating Form 328-D:" << endl;
	Form form3("328-D", 49, 1);
	cout << form3 << endl << endl;
	cout << "Bureaucrat: " << worker1.getName() << " tries to sign form " << form3.getName() << ":" << endl;
	worker1.signForm(form3);
	std::cout << endl << "Incremeting grade " << worker1.getName() << std::endl;
	worker1.incrementGrade();
	cout << worker1 << endl << endl;
	cout << "Bureaucrat: " << worker1.getName() << " tries to sign form " << form3.getName() << ":" << endl;
	worker1.signForm(form3);
	cout << form3 << endl;
	cout << endl << "Bureaucrat: " << worker1.getName() << " tries to sign form " << form3.getName() << ":" << endl;
	worker1.signForm(form3);

	try {
		cout << endl << form3.getName() << " beSigned by " << worker1.getName() << ":" << endl;
		form3.beSigned(worker1);
	}
	catch (std::exception & e) {
		std::cout << R << worker1.getName() << " could not sign Form " << form3.getName() << " [" << e.what() << "]" << END << std::endl;
	}

	cout << "Creating Bureaucrat:" << endl;
	Bureaucrat worker2("SpongBob", 1);
	cout << worker2 << endl;
	cout << endl << "Creating Form 328-E:" << endl;
	Form form4("328-E", 150, 1);
	cout << form4 << endl << endl;
	cout << "Bureaucrat: " << worker2.getName() << " tries to sign form " << form4.getName() << ":" << endl;
	worker2.signForm(form4);
	cout << form4 << endl;
	cout << endl << "Bureaucrat: " << worker2.getName() << " tries to sign form " << form4.getName() << ":" << endl;
	worker2.signForm(form4);

	try {
		cout << endl << form4.getName() << " beSigned by " << worker2.getName() << ":" << endl;
		form4.beSigned(worker2);
	}
	catch (std::exception & e) {
		std::cout << R << worker2.getName() << " could not sign Form " << form4.getName() << " [" << e.what() << "]" << END << std::endl;
	}
	return (0);
}
