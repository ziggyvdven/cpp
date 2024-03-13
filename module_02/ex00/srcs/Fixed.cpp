/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:57:49 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/13 16:25:05 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int	Fixed::_nbits = 8;

Fixed::Fixed( void ) : _n( 0 ){
	
	std::cout << "Default constructor called" << std::endl;

	return;
}

Fixed::Fixed( Fixed const & src ){
	
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return;
}

Fixed::~Fixed( void ){
	
	std::cout << "Destructor called" << std::endl;
	
}

Fixed &		Fixed::operator=( Fixed const & rhs ){
	
	std::cout << "Copy assignment operator called" << std::endl;
	this->_n = rhs.getRawBits();
	
	return *this;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawbits member function called" << std::endl;
	return ( this->_n );
}

void Fixed::setRawBits(int const n)
{
	this->_n = n;
	return;
}

std::ostream &	operator<< (std::ostream & o, Fixed const &rhs){
	o << rhs.getRawBits();
	return o;
}