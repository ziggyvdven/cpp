/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:57:49 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/08 18:33:09 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int	Fixed::_nbits = 8;

/**************************  CANONICAL FORM  **********************************/
/******************************************************************************/

/*DEFAULT CONSTRUCTOR/DESTRUCTOR **********************************************/

Fixed::Fixed( void ) : _n( 0 ){
	
	std::cout << "Default constructor called" << std::endl;

	return;
}

Fixed::~Fixed( void ){
	
	std::cout << "Destructor called" << std::endl;
	
}

/*DEFAULT COPY CONSTRUCTOR ****************************************************/

Fixed::Fixed( Fixed const & src ){
	
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return;
}

/*COPY ASSIGMENTN OPERATOR OVERLOAD *******************************************/

Fixed &		Fixed::operator=( Fixed const & rhs ){
	
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_n = rhs.getRawBits();
	
	return *this;
}

/******************************************************************************/
/******************************************************************************/

/*PARAMETRIC CONSTRUCTOR ******************************************************/

Fixed::Fixed( int const n) : _n(n << this->_nbits){
	
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed( float const f) {
	float result;
	
	std::cout << "Float constructor called" << std::endl;
	result = roundf(f * (1 << this->_nbits));
	this->_n = (int)result; 	

	return;
}

/*GETTERS & SETTERS ***********************************************************/

int		Fixed::getRawBits( void ) const {
	
	// std::cout << "getRawbits member function called" << std::endl;
	return ( this->_n );
}

void	Fixed::setRawBits(int const n)
{
	this->_n = n;
	return;
}

float	Fixed::toFloat( void ) const {
	
	float	f;
	
	f = (float)this->_n / (1 << this->_nbits);
	return (f);
}

int 	Fixed::toInt( void ) const{
	
	return (this->_n >> this->_nbits);
	
}

/*OPERATORS OVERLOADED ********************************************************/

std::ostream &	operator<< (std::ostream & o, Fixed const &rhs){
	o << rhs.toFloat();
	return o;
}