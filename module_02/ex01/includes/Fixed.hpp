/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:49:39 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/08 18:36:22 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef	FIXED_HPP
#define		FIXED_HPP

#include 	<iostream>
#include	<cmath>

class Fixed{
	public:
		Fixed( void ); // CANONICAL Default.
		Fixed( Fixed const & src); // CANONICAL Copy.
		Fixed( const int n); // Parametric.
		Fixed( const float f); // Parametric.
		~Fixed( void ); // CANONICAL Destructor

		Fixed &		operator=( Fixed const & rhs ); // CANONICAL ASSIGNATION

		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
		float	toFloat( void ) const;
		int 	toInt( void ) const;
		
	private:
		
		int					_n;
		static const int 	_nbits;
};

std::ostream &	operator<<( std::ostream & o, Fixed const & i );

#endif
