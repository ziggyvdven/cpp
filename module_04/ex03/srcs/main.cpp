/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:03:20 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/22 20:34:51 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

void cleanfloor()
{
	for(int i = 0; i < 100; i++)
	{
		if (g_floor[i])
			delete g_floor[i];
	}
}

int main() {
	
	// Ice* i = new Ice();
	// Cure* bandage = new Cure();
	// Character jake("jake");
	// Character dumbledore("dumbledore");

	// jake.equip(i);
	// jake.equip(bandage);
	// // jake.equip(bandage);
	// // jake.equip(bandage);
	// // jake.equip(bandage);
	// // jake.equip(bandage);

	// jake.use(3, dumbledore);

	// // jake.unequip(0);
	// // jake.unequip(1);
	// // jake.unequip(2);
	// // jake.unequip(3);

	// // Character mage3(jake);
	// // mage3.equip(bandage);
	// // jake.unequip(0);
	
	// // dumbledore.equip(i);
	// // dumbledore = jake;
	// // std::cout << *bandage << std::endl;
	// // std::cout << *i << std::endl;

	// // Ice* ice = i->clone();
	// // std::cout << ice->getType() << std::endl;
	// delete i;
	// delete bandage;
	// cleanfloor();

	IMateriaSource* src = new MateriaSource(); 
	src->learnMateria(new Ice()); 
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice"); 
	me->equip(tmp);
	delete tmp;
	// tmp = src->createMateria("cure"); 
	// me->equip(tmp);
	
	ICharacter* bob = new Character("bob"); 
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob; 
	delete me; 
	delete src;
		
	return 0;
}
