/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/02 17:11:05 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>


using std::cout;
using std::endl;
using std::exception;
using std::string;

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class Span {
public:
						Span ( Span const & src);
						Span ( const unsigned int N );
						~Span( void );

	Span &				operator=( Span const & rhs );
	void				addNumber( const int  i );
	int					shortestSpan( void );
	int					longestSpan( void );
	void				addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int					getData( int i ) const;
	unsigned			getDataSize( void ) const ;
	unsigned			getN() const;
	

private:
						Span ( void );
	
	unsigned int 		_N;
	std::vector<int>	_Data;

};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */