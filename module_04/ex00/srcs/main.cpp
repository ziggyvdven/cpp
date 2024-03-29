/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:03:20 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/29 11:53:46 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

int main() {
	
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl; 
	j->makeSound(); //will output the cat sound! 
	std::cout << i->getType() << " " << std::endl; 
	i->makeSound();
	std::cout << meta->getType() << " " << std::endl; 
	meta->makeSound();
	delete (i);
	delete (j);
	delete (meta);

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() << " " << std::endl; 
	k->makeSound(); //will output the animal sound!
	meta2->makeSound();
	delete (k);
	delete (meta2);
	return 0;
}