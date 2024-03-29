/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:03:20 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/29 12:06:39 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

void	testshallowness(){

	std::cout << std::endl << BOLD << "TEST 2 DEEP COPIES:" << END << std::endl;
	std::cout << "Creating Dog instance: Idefix" << std::endl;
	Dog* idefix = new Dog();
	std::cout << "Creating Cat instance: Garfield" << std::endl;
	Cat* garfield = new Cat();
	std::cout << std::endl;

	std::cout << BOLD << "Setting ideas:" << END << std::endl;
	std::cout << idefix->getType() << ": idefix setting idea[0] to: Where is Asterix?" << std::endl;
	idefix->setIdea(0, "Where is Asterix?");
	std::cout << idefix->getType() << ": idefix setting idea[1] to: Where is Obelix?" << std::endl;
	idefix->setIdea(1, "Where is Obelix?");
	std::cout << idefix->getType() << ": idefix setting idea[100] to: Where is Obelix?" << std::endl;
	idefix->setIdea(100, "Where is Obelix?");
	std::cout << std::endl;
	
	std::cout << BOLD << "Getting ideas:" << END << std::endl;
	std::cout << idefix->getType() << ": idefix idea[0]:" << idefix->getIdea(0) << std::endl;
	std::cout << idefix->getType() << ": idefix idea[1]:" << idefix->getIdea(1) << std::endl;
	std::cout << idefix->getType() << ": idefix idea[100]:" << idefix->getIdea(100) << std::endl;
	std::cout << std::endl;

	std::cout << "Creating Dog instance: Snoopy" << std::endl;
	Dog* snoopy = new Dog();
	
	std::cout << "Deep copying idefix to snoopy (assignment)" << std::endl;
	*snoopy = *idefix; // creates a deep copy
	std::cout << std::endl;
	std::cout << idefix->getType() << ": snoopy idea[0]:" << snoopy->getIdea(0) << std::endl;
	std::cout << idefix->getType() << ": snoopy idea[1]:" << snoopy->getIdea(1) << std::endl;
	std::cout << std::endl;
	
	std::cout << BOLD << "Setting new ideas:" << END << std::endl;
	std::cout << idefix->getType() << ": Snoopy setting idea[0] to: Where is Charlie?" << std::endl;
	snoopy->setIdea(0, "Where is Charlie?");
	std::cout << idefix->getType() << ": Snoopy setting idea[1] to: Fuck Charlie!" << std::endl;
	snoopy->setIdea(1, "Fuck Charlie!");
	std::cout << std::endl;
	
	std::cout << BOLD << "Getting ideas:" << END << std::endl;
	std::cout << idefix->getType() << ": idefix idea[0]:" << idefix->getIdea(0) << std::endl;
	std::cout << idefix->getType() << ": idefix idea[1]:" << idefix->getIdea(1) << std::endl;
	std::cout << snoopy->getType() << ": snoopy idea[0]:" << snoopy->getIdea(0) << std::endl;
	std::cout << snoopy->getType() << ": snoopy idea[1]:" << snoopy->getIdea(1) << std::endl;
	std::cout << std::endl;

	std::cout << garfield->getType() << ": Garfield setting idea[0] to: GHJFSGJdfgs LASAGNA!!" << std::endl;
	garfield->setIdea(0, "GHJFSGJdfgs LASAGNA!!");
	std::cout << garfield->getType() << ": Garfield idea[0]:" << garfield->getIdea(0) << std::endl;

	std::cout << std::endl << "Deep copying garfield to tom (copy constructor)" << std::endl;
	Cat tom(*garfield);
	std::cout << tom.getType() << ": tom idea[0]:" << tom.getIdea(0) << std::endl;
	std::cout << BOLD << "Deleting garfield:" << END << std::endl;
	delete garfield;
	std::cout << tom.getType() << ": tom idea[0]:" << tom.getIdea(0) << std::endl;
		
	std::cout << BOLD << "Deleting:" << END << std::endl;
	delete idefix;//should not create a leak 
	delete snoopy;
	return ;
}

int main() {
	
	Animal* animals[10];
	
	std::cout << BOLD << "TEST 1 SUBJECT TESTING:" << END << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else 
			animals[i] = new Cat();
	}

	for (size_t i = 0; i < 10; i++){
			std::cout << "Animal getType: " << animals[ i ]->getType() << " -> makeSound: ";
			animals[i]->makeSound();
	}

	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
	}

	const Animal* j = new Dog(); 
	const Animal* i = new Cat();
	delete j;//should not create a leak 
	delete i;

	testshallowness();
	
	return 0;
}
