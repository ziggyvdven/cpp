/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/17 20:39:41 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp" 

Base::~Base()
{
}

Base * generate(void)
{
	srand((unsigned) time(NULL));
	int random = rand() % 3;
	switch (random){
		case 0:
			cout << "Pointer to Object A created" << endl;
			return (new A());
		case 1:
			cout << "Pointer to Object B created" << endl;
			return (new B());
		case 2:
			cout << "Pointer to Object C created" << endl;
			return (new C());
		default:
			throw (std::runtime_error("RANDOMIZER FAILED"));
	}
	throw (std::runtime_error("RANDOMIZER FAILED"));
}

void identify(Base* ptr)
{
	if (!ptr)
		return;
	if (dynamic_cast<A*>(ptr))
		cout << "A" << endl;
	if (dynamic_cast<B*>(ptr))
		cout << "B" << endl;
	if (dynamic_cast<C*>(ptr))
		cout << "C" << endl;
	
}

void identify(Base& ref)
{
	try
	{	
		(void)(dynamic_cast<A&>(ref));
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		(void)(dynamic_cast<B&>(ref));
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try
	{
		(void)(dynamic_cast<C&>(ref));
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
}
