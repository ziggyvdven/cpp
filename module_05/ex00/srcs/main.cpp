/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/28 18:56:08 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
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

	try {
		Bureaucrat worker("Squidward", 150);
		worker.decrementGrade();
	}
	catch (std::exception & e) {
		std::cout << "Could not decrement Bureaucrat:   [" << e.what() << " ]" << std::endl;
	}

	try {
		Bureaucrat worker("Squidward", 1);
		worker.incrementGrade();
	}
	catch (std::exception & e) {
		std::cout << "Could not decrement Bureaucrat:   [" << e.what() << "]" << std::endl;
	}

	try {
		Bureaucrat worker("Squidward", 1);
		std::cout << worker << std::endl;
		worker.decrementGrade();
		std::cout << worker << std::endl;
		worker.incrementGrade();
		worker.incrementGrade();
	}
	catch (std::exception & e) {
		std::cout << "Could not decrement Bureaucrat:   [" << e.what() << "]" << std::endl;
	}
	
	std::cout << std::endl << "---------- Testing increment/decrement---------" << std::endl;
	Bureaucrat worker("Squidward", 1);
	std::cout << "Grade before for "<< worker << std::endl;
	worker.decrementGrade();
	std::cout << "Grade after decrement for "<< worker << std::endl;
	worker.decrementGrade();
	std::cout << "Grade after decrement for "<< worker << std::endl;
	worker.decrementGrade();
	std::cout << "Grade after decrement for "<< worker << std::endl;
	worker.incrementGrade();
	std::cout << "Grade after increment for "<< worker << std::endl;
	
	return (0);
}
