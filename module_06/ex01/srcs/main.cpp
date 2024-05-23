/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/25 13:47:30 by zvan-de-         ###   ########.fr       */
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
	cout << "Before serializing: " << endl << "i = " << a->i << endl << "a = " << a->str << endl;
	uintptr_t p = serialize(a);
	cout << "Serializing..." << endl << "uintptr value: " << p << endl;
	Data *ptr = deserialize(p);
	cout << "Deserializing..." << endl;
	cout << "After serializing: " << endl << "i = " << ptr->i << endl << "a = " << ptr->str << endl;
	delete a;
	return (0);
}
