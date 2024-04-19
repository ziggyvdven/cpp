/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/19 17:47:49 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <stdexcept>

using std::cout;
using std::endl;
using std::exception;
using std::string;

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

template< typename T = int >
class Array {
public:
	Array ( void ):  _arr(new T()), _size(0){
		cout << "default constructor called" << endl;
	};
	
	Array ( const unsigned int & n):  _arr(new T[n]), _size(n){
		cout << "constructor by parameter called" << endl;
	};

	Array ( Array const & src){
		cout << "copy constructor called" << endl;
		*this = src;
	};
	
	~Array( void ){
		delete[] _arr;
	};

	Array &		operator=( Array const & rhs ){
		cout << "= operator overide called" << endl;
		if ( this != &rhs ){
			delete[] _arr;
			_arr = NULL;
			_arr = new T[rhs._size];
			for (unsigned i = 0; i < rhs._size; i++)
				_arr[i] = rhs._arr[i];
			_size = rhs._size;
		}
		return *this;
		
	};

	T &		operator[]( unsigned int const & i ){
		// cout << "[] operator overide called" << endl;
		if (i > _size - 1)
			throw (std::runtime_error("INDEX OUT OF BOUNDS"));
		return (_arr[i]);
		
	};

	T			get_arr( void ) const{
		return (*_arr);
	};

	unsigned int	size( void ) const{
		return (_size);
	};


private:
	T* 				_arr;
	unsigned int	_size;

};

template< typename T >
std::ostream &			operator<<( std::ostream & o, Array<T>& i )
{
	o << "{";
	for ( unsigned int j = 0; j < i.size(); j++)
	{
		if (j < i.size() - 1)
			o << i[j] << ", ";
		else 
			o << i[j];
	}
	o << "}";
	return o;
}

#endif /* ******************************************************* ARRAY_H */