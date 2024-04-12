/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/12 16:39:49 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serialize.hpp" 
#include <stdio.h>

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main( void )
{
	Data	*a = new Data;
	
	a->i = 42;
	a->str = "TEST";
	uintptr_t p = serialize(a);
	cout << &a << endl;
	printf("p = %lu\n", p);
	Data *ptr = deserialize(p);
	std::cout << ptr->str << std::endl;
	std::cout << ptr->i << std::endl;
	delete a;
	return (0);
}
