/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:57:49 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/21 15:47:19 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int	Fixed::_nbits = 8;

/**************************  CANONICAL FORM  **********************************/
/******************************************************************************/

/*DEFAULT CONSTRUCTOR/DESTRUCTOR **********************************************/

Fixed::Fixed( void ) : _n( 0 ){
	
	// std::cout << "Default constructor called" << std::endl;

	return;
}

Fixed::~Fixed( void ){
	
	// std::cout << "Destructor called" << std::endl;
	
}

/*DEFAULT COPY CONSTRUCTOR ****************************************************/

Fixed::Fixed( Fixed const & src ){
	
	// std::cout << "Copy constructor called" << std::endl;
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
	
	// std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed( float const f) {
	float result;
	
	// std::cout << "Float constructor called" << std::endl;
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
/******************************************************************************/

std::ostream &	operator<< (std::ostream & o, Fixed const &rhs){
	o << rhs.toFloat();
	return o;
}

/*COMPARISON OPERATORS*********************************************************/

bool 		Fixed::operator>( Fixed const & rhs ) const{
	
	if (this->getRawBits() > rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool 		Fixed::operator<( Fixed const & rhs ) const{
	
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool 		Fixed::operator>=( Fixed const & rhs ) const{
	
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool 		Fixed::operator<=( Fixed const & rhs ) const{
	
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool 		Fixed::operator==( Fixed const & rhs ) const{
	
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool 		Fixed::operator!=( Fixed const & rhs ) const{
	
	if (this->getRawBits() != rhs.getRawBits())
		return (true);
	else
		return (false);
}

/*ARITHMETIC OPERATORS*********************************************************/


Fixed 		Fixed::operator+( Fixed const & rhs ) const{
	Fixed result;

	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed 		Fixed::operator-( Fixed const & rhs ) const{
	Fixed result;

	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed 		Fixed::operator*( Fixed const & rhs ) const{
	Fixed result;

	result.setRawBits(this->getRawBits() * rhs.getRawBits() >> this->_nbits);
	return (result);
}

Fixed 		Fixed::operator/( Fixed const & rhs ) const{
	Fixed result;

	result.setRawBits((this->getRawBits() << this->_nbits) / rhs.getRawBits());
	return (result);
}

/*INCREMENT/DECREMENT OPERATORS************************************************/

Fixed 		&Fixed::operator++( void ) {
    this->_n += 1;
    return *this;
}

Fixed 		Fixed::operator++( int ) { 
    Fixed temp(*this);
    this->_n += 1;
    return temp;
}

Fixed 		&Fixed::operator--( void ) {
    this->_n = this->_n - 1;
    return *this;
}

Fixed 		Fixed::operator--( int ) { 
    Fixed temp(*this);
    this->_n = this->_n - 1;
    return temp;
}

Fixed	&Fixed::min( Fixed &lhs, Fixed &rhs ){
	Fixed &result = (lhs < rhs) ? lhs : rhs;
	return (result);
}

Fixed	&Fixed::max( Fixed &lhs, Fixed &rhs ){
	Fixed &result = (lhs > rhs) ? lhs : rhs;
	return (result);
}

const Fixed	&Fixed::min( const Fixed &lhs, const Fixed &rhs ) {
	if ( lhs < rhs){
		const Fixed &result = lhs;
		return ( result );
	}
	else {
		const Fixed &result = rhs;
		return ( result );
	}
}

const Fixed	&Fixed::max( const Fixed &lhs, const Fixed &rhs ) {
	if ( lhs > rhs){
		const Fixed &result = lhs;
		return ( result );
	}
	else {
		const Fixed &result = rhs;
		return ( result );
	}
}