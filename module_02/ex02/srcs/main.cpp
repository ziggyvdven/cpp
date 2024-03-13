/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:41:59 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/13 15:37:09 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Fixed.hpp"

int main( void ) {
	Fixed const a( 3.5f );
	Fixed const b( 1.5f );
	Fixed c;
	
	std::cout << "a = " << a.toFloat() << std::endl;
	std::cout << "b = " << b.toFloat() << std::endl;

	c = a + b;
	std::cout << "c = a + b 	c = " << c.toFloat() << std::endl;

	c = a - b;
	std::cout << "c = a - b 	c = " << c.toFloat() << std::endl;

	c = a * b;
	std::cout << "c = a * b 	c = " << c.toFloat() << std::endl;
	
	c = a / b;
	std::cout << "c = a / b 	c = " << c.toFloat() << std::endl;

	if (a > b)
		std::cout << "a > b 	Result: " << a.toFloat() << " is bigger than " << b.toFloat() << std::endl;
	else
		std::cout << "a > b 	Result: " << a.toFloat() << " is not bigger than " << b.toFloat() << std::endl;

	if (a < b)
		std::cout << "a < b 	Result: " << a.toFloat() << " is smaller than " << b.toFloat() << std::endl;
	else
		std::cout << "a < b 	Result: " << a.toFloat() << " is not smaller than " << b.toFloat() << std::endl;

	if (a >= b)
		std::cout << "a >= b 	Result: " << a.toFloat() << " is bigger or equal to " << b.toFloat() << std::endl;
	else
		std::cout << "a >= b 	Result: " << a.toFloat() << " is not smaller or equal to " << b.toFloat() << std::endl;

	if (a <= b)
		std::cout << "a <= b 	Result: " << a.toFloat() << " is smaller or equal to " << b.toFloat() << std::endl;
	else
		std::cout << "a <= b 	Result: " << a.toFloat() << " is not smaller or equal to " << b.toFloat() << std::endl;

	if (a == b)
		std::cout << "a == b 	Result: " << a.toFloat() << " is equal to " << b.toFloat() << std::endl;
	else
		std::cout << "a == b 	Result: " << a.toFloat() << " is not equal to " << b.toFloat() << std::endl;

	if (a != b)
		std::cout << "a != b 	Result: true " << std::endl;
	else
		std::cout << "a != b 	Result: false "  << std::endl;
	
	std::cout << std::endl << std::endl;

	Fixed d;
	Fixed const e( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << d << std::endl; // Is equal to 0.

	std::cout << ++d << std::endl; // Shows incremented value.
	std::cout << d << std::endl; // Shows value of a.
	std::cout << d++ << std::endl; // Shows a before incrementation.
	std::cout << d << std::endl; // Shows value of a.

	std::cout << e << std::endl;

	std::cout << Fixed::max( d, e ) << std::endl;
	
	return 0; 
}
