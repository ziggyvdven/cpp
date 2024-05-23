/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:14:05 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/02 16:20:30 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Span::Span(): _N(0) {
	std::cout << G << "Span Default constructor called" << END << std::endl;
}

Span::Span(const unsigned int N): _N(N) {
	std::cout << G << "Span constructor by parameter called" << END << std::endl;
}

Span::Span( const Span & src ){
	std::cout << G << "Span Copy constructor called" << END << std::endl;
	_N = src._N;
	_Data = src._Data;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span(){
	std::cout << R << "Span Destructor called" << END << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	std::cout << "Span Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		_N = rhs._N;
		_Data = rhs._Data;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void		Span::addNumber( const int  i ){
	
	if (_Data.size() < _N)
		_Data.push_back(i);
	else 
		throw (std::runtime_error("SPAN HOLDS MAXIMUM NUMBER OF INTEGERS"));
}


void		Span::addRange( std::vector<int>::iterator begin, std::vector<int>::iterator end){
	if ((_Data.size() + (end - begin)) > _N || _N == 0)
		throw (std::runtime_error("SPAN HOLDS MAXIMUM NUMBER OF INTEGERS"));
	else 
		_Data.insert(_Data.end(), begin, end);
}

int			Span::shortestSpan( void ){
	
	std::vector<int> 	data_copy(_Data);
	int					span = INT_MAX;

	if (_Data.size() > 1){
		sort(data_copy.begin(), data_copy.end());
		for (unsigned long i = 1; i < data_copy.size(); i++)
		{
			if (span > (data_copy[i] - data_copy[i - 1]))
				span = (data_copy[i] - data_copy[i - 1]);
		}	
		return (span);
	}
	else
		throw (std::runtime_error("NOT ENOGH VALUES TO FIND LONGEST SPAN"));
}

int			Span::longestSpan( void ){
	
	if (_Data.size() > 1){
		return (*max_element(_Data.begin(), _Data.end()) - *min_element(_Data.begin(), _Data.end()));
	}
	else
		throw (std::runtime_error("NOT ENOGH VALUES TO FIND LONGEST SPAN"));
}


std::ostream &			operator<<( std::ostream & o, Span const & s )
{
	o << "{";
	for (unsigned i = 0; i < s.getDataSize(); i++)
	{
		o << s.getData(i);
		if (i !=  s.getDataSize() - 1)
			o << ", ";
	}
	o << "}" << std::endl;
	return o;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned	Span::getN() const{
	return (_N);
}

int			Span::getData( int i ) const{
	return (_Data[i]);
}

unsigned	Span::getDataSize( void ) const
{
	return (_Data.size());
}



/* ************************************************************************** */