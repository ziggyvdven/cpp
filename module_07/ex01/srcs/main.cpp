/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/19 14:32:47 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp" 
#include "stdio.h"


int main()
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	int arr[5] = {1,2,3,4,5};
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	cout << std::setprecision(1);
	cout << endl;
	iter(arr, 5, &print);
	cout << endl;
	iter(arr, 5, &increment);
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl << endl;

	double arr2[5] = {1,2,3,4,5};
	cout << endl;
	iter(arr2, 5, &print);
	cout << endl;
	iter(arr2, 5, &increment);
	for (int i = 0; i < 5; i++)
		cout << arr2[i] << " ";
	cout << endl << endl;

	float arr3[5] = {1.0f,2.0f,3.0f,4.0f,5.0f};
	cout << endl;
	iter(arr3, 5, &print);
	cout << endl;
	iter(arr3, 5, &increment);
	for (int i = 0; i < 5; i++)
		cout << arr3[i] << " ";
	cout << endl << endl;

	char arr4[5] = {'A','B','C','D','E'};
	cout << endl;
	iter(arr4, 5, &print);
	cout << endl;
	iter(arr4, 5, &increment);
	for (int i = 0; i < 5; i++)
		cout << arr4[i] << " ";
	cout << endl << endl;

	string arr5[5] = {"one", "two", "three", "four", "five"};
	cout << endl;
	iter(arr5, 5, &print);
	cout << endl;
	// iter(arr5, 5, &increment);
	// for (int i = 0; i < 5; i++)
	// 	cout << arr5[i] << " ";
	// cout << endl << endl;
	return (0);
}
