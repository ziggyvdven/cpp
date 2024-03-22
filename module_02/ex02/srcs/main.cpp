/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:41:59 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/21 15:46:58 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Fixed.hpp"

int main( void ) {
	Fixed a( 3.5f );
	Fixed b( 1.5f );
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
	std::cout << "c = a / b 	c = " << c.toFloat() << std::endl << std::endl;

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
	
	
	b = a;
	std::cout << std::endl << "a = " << a.toFloat() << std::endl;
	std::cout << "b = " << b.toFloat() << std::endl;
	a++;
	std::cout << "a++ Result: " << a << std::endl;
	a--;
	std::cout << "a-- Result: " << a << std::endl;
	
	std::cout << "Showing (a++ == b)" << std::endl;
	if (a++ == b)
		std::cout << "True " << a << std::endl;
	std::cout << "Showing (++a == b)" << std::endl;
	if (++a == b)
		std::cout << "True" << a << std::endl; // does not print
	
	a = b;
	std::cout << std::endl << "a = " << a.toFloat() << std::endl;
	std::cout << "b = " << b.toFloat() << std::endl;
	std::cout << "Showing (a-- == b)" << std::endl;
	if (a-- == b)
		std::cout << "True " << a << std::endl;
	std::cout << "Showing (--a == b)" << std::endl;
	if (--a == b)
		std::cout << "True" << a << std::endl; // does not print
	

	std::cout << std::endl << "Example from the subject:" << std::endl;

	Fixed d;
	Fixed const e( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << d << std::endl; // Is equal to 0.

	std::cout << ++d << std::endl; // Shows incremented value.
	std::cout << d << std::endl; // Shows value of a.
	std::cout << d++ << std::endl; // Shows a before incrementation.
	std::cout << d << std::endl; // Shows value of a.

	std::cout << e << std::endl;
	std::cout << Fixed::max( d, e ) << std::endl;
	std::cout << Fixed::min( d, e ) << std::endl;

	// Fixed const f( 1.5f );
	// Fixed const g( 3.5f );
	// std::cout << std::endl << "f = " << f.toFloat() << std::endl;
	// std::cout << "g = " << g.toFloat() << std::endl;
	// std::cout << Fixed::max( f, g ) << std::endl;
	// std::cout << Fixed::min( f, g ) << std::endl;
	
	return 0; 
}
