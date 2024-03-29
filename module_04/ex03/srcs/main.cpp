/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:03:20 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/28 16:25:54 by zvan-de-         ###   ########.fr       */
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
	
	std::cout << "___LEARNING NEW MATERIA___" << std::endl;
	IMateriaSource* src = new MateriaSource(); 
	src->learnMateria(new Ice()); 
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	std::cout << "Trying to learn 5th materia" << std::endl;
	src->learnMateria(new Ice());

	
	std::cout << std::endl << "___CREATING AND EQUIPING NEW MATERIA___" << std::endl;
	Cure* attack = new Cure();
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("cure"); 
	me->equip(tmp);
	tmp = src->createMateria("ice"); 
	me->equip(tmp);
	tmp = src->createMateria("ice"); 
	me->equip(tmp);
	tmp = src->createMateria("cure"); 
	me->equip(tmp);
	tmp = src->createMateria("cure"); 
	me->equip(tmp);
	me->equip(tmp);
	me->equip(attack);
	delete attack;
	delete tmp;
	tmp = src->createMateria("kamehameha"); 
	
	std::cout << std::endl << "___TESTING DEEP COPY MATERIASOURCE___" << std::endl;
	ICharacter* bob = new Character("bob"); 
	ICharacter* dumbledore = new Character("dumbledore"); 
	
	std::cout << "creating MaterialSource: 2" << std::endl;
	MateriaSource* src1 = new MateriaSource(); 
	src1->learnMateria(new Ice()); 
	src1->learnMateria(new Cure());
	
	std::cout << "creating MaterialSource: 3" << std::endl;
	MateriaSource src3(*src1);
	std::cout << "DELETING MaterialSource: 1" << std::endl;
	delete src1;
	std::cout << "using MaterialSource: 3" << std::endl;
	tmp = src3.createMateria("cure"); 
	dumbledore->equip(tmp);

	std::cout << std::endl << "___USING MATERIAS___" << std::endl;
	me->use(0, *bob);
	me->unequip(0);
	me->unequip(5);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(4, *bob);
	me->use(3, *dumbledore);
	me->use(1, *dumbledore);
	
	dumbledore->use(0, *bob);
	delete bob;
	delete dumbledore; 
	delete me; 
	delete src;
	cleanfloor();
		
	return 0;
}
