/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:49:39 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/08 22:03:38 by zvan-de-         ###   ########.fr       */
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
		
		bool			operator>( Fixed const & rhs)  const;
		bool			operator<( Fixed const & rhs)  const;
		bool			operator>=( Fixed const & rhs)  const;
		bool			operator<=( Fixed const & rhs)  const;
		bool			operator==( Fixed const & rhs)  const;
		bool			operator!=( Fixed const & rhs)  const;

		Fixed			operator+( Fixed const & rhs)  const;
		Fixed			operator-( Fixed const & rhs)  const;
		Fixed			operator*( Fixed const & rhs)  const;
		Fixed			operator/( Fixed const & rhs)  const;

		Fixed			&operator++( void ); //Pre-increment
		Fixed			&operator--( void ); //Pre-decrement
		Fixed			operator++( int ); //Post-increment
		Fixed			operator--( int ); //post-increment

		static Fixed 		&min( Fixed &lhs, Fixed &rhs );
		static Fixed 		&max( Fixed &lhs, Fixed &rhs );
		static const Fixed 	&min(const Fixed &first, const Fixed &second);
    	static const Fixed 	&max(const Fixed &first, const Fixed &second);

		int				getRawBits( void ) const;
		void			setRawBits( int const raw);
		float			toFloat( void ) const;
		int 			toInt( void ) const;
		
	private:
		
		int					_n;
		static const int 	_nbits;
};

std::ostream &	operator<<( std::ostream & o, Fixed const & i );

#endif
