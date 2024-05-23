/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/03 16:48:18 by zvan-de-         ###   ########.fr       */
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
		cout << G << "default constructor called" << END << endl;
	};
	
	Array ( const unsigned int & n):  _arr(new T[n]), _size(n){
		cout << G << "constructor by parameter called" << END << endl;
	};

	Array ( Array const & src) : _arr ( new T[src._size] ), _size (src._size){
		cout << G << "copy constructor called" << END << endl;
		for ( unsigned int i( 0 ); i < _size; i++ )
            _arr[i] = src._arr[i];
	};
	
	~Array( void ){
		cout << R << "Destructor called" << END << endl;
		delete[] _arr;
	};

	Array &		operator=( Array const & rhs ){
		cout << B << "= operator overide called" << END << endl;
		if ( this != &rhs ){
			if (_size)
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