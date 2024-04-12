/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/12 16:54:57 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp" 

Base * generate(void)
{
	srand((unsigned) time(NULL));
	int random = rand() % 3;
	switch (random){
		case 0:
			std::cout << "A creates " <<  std::endl;
			return (new A());
			break;
		case 1:
			std::cout << "B creates " << std::endl;
			return (new B());
			break;
		case 2:
			std::cout << "C creates "  << std::endl;
			return (new C());
			break;
		default:
			std::cout << "Form does not exist" << std::endl;
			break;
	}
}

void identify(Base* p)
{
	
}

void identify(Base& p)
{

}
