/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/06/12 16:19:27 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp" 

int main()
{
    Array< float > test;

    Array<> arr( 10 );
    Array< int > arr2( arr );
	Array< int > arr3( 5 );

    for ( unsigned int i = 0; i < arr.size(); i++ )
        arr[i] = i * 2;

	for ( unsigned int i = 0; i < arr3.size(); i++ )
        arr3[i] = i;

    std::cout << "Array 1: " << arr << std::endl;
	std::cout << "Array 2: " << arr2 << std::endl;
	std::cout << "Array 3: " << arr3 << std::endl;

    arr2 = arr;

    std::cout << "Array 2: " << arr2 << std::endl;

	arr3 = arr;

	std::cout << "Array 3: " << arr2 << std::endl;

    try {
        std::cout << "Accessing arr[5]: " << arr[5] << std::endl;
        std::cout << "Accessing arr[10]: " << arr[10] << std::endl;
    } catch ( std::exception& e ) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return ( 0 );
}
