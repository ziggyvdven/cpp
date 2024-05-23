/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:21:33 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/25 13:40:03 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/converter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Converter::Converter(): _i(0), _c(0), _f(0.0f), _d(0.0), _pseudo(false) {
	
	_c_possible = true;
	_i_possible = true;
	_f_possible = true;
	_literals[0] = "char";
	_literals[1] = "int";
	_literals[2] = "float";
	_literals[3] = "sfloat";
	_literals[4] = "double";
	_literals[5] = "sdouble";
	_func[0] = &Converter::convert_char;
	_func[1] = &Converter::convert_int;
	_func[2] = &Converter::convert_float;
	_func[3] = &Converter::convert_sfloat;
	_func[4] = &Converter::convert_double;
	_func[5] = &Converter::convert_sdouble;
	
}

Converter::Converter( const Converter & src ){
	_c_possible = true;
	_i_possible = true;
	_f_possible = true;
	_literals[0] = "char";
	_literals[1] = "int";
	_literals[2] = "float";
	_literals[3] = "sfloat";
	_literals[4] = "double";
	_literals[5] = "sdouble";
	_func[0] = &Converter::convert_char;
	_func[1] = &Converter::convert_int;
	_func[2] = &Converter::convert_float;
	_func[3] = &Converter::convert_sfloat;
	_func[4] = &Converter::convert_double;
	_func[5] = &Converter::convert_sdouble;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Converter::~Converter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Converter &				Converter::operator=( Converter const & rhs )
{
	if ( this != &rhs )
	{
		_i = rhs._i;
		_c = rhs._c;
		_f = rhs._f;
		_d = rhs._d;
		_pseudo = rhs._pseudo;
		_c_possible = rhs._c_possible;
		_i_possible = rhs._c_possible;
		_f_possible = rhs._c_possible;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Converter::convert(const string type, string input){
	if (input.empty() || type.empty())
		return;
	for (int i = 0; i <= 6; i++)
		if (type == this->_literals[i])
		{
			switch (i){
				case 0:
					(this->*_func[0])(input);
					break;
				case 1:
					(this->*_func[1])(input);
					break;
				case 2:
					(this->*_func[2])(input);
					break;
				case 3:
					(this->*_func[3])(input);
					break;
				case 4:
					(this->*_func[4])(input);
					break;
				case 5:
					(this->*_func[5])(input);
					break;
				default:
					cout << "TYPE UNKNOWN" << endl;
					break;
			}
		}
	print_conversion();
	reset_values();
	return ;
}

void	Converter::print_conversion( void ){
	
	if (_pseudo || _i_possible == false)
		cout << "char: impossible" << endl;
	else if (_c)
		cout << "char: '" << _c << "'" << endl;
	else
		cout << "char: Non displayable" << endl;
	if (_pseudo || _i_possible == false)
		cout << "int: impossible" << endl;
	else	
		cout << "int: " << _i << endl;
	if (!_f_possible)
		cout << "float: impossible" << endl;
	else
		cout << "float: " << _f << "f" << endl;
	cout << "double: " << _d << endl;		
}

void Converter::convert_char( string input ){
	_c = static_cast<char>(input[0]);
	_i = static_cast<int>(_c);
	_f = static_cast<float>(_c);
	_d = static_cast<double>(_c);
}

void Converter::convert_int( const string input ){
	_i = std::stoi(input);
	_c = static_cast<char>(_i);
	if (_i < 32 || _i > 126)
		_c = 0;
	_f = static_cast<float>(_i);
	_d = static_cast<double>(_i);
}

void Converter::convert_float( const string input ){
	_f = std::stof(input);
	_i = static_cast<int>(_f);
	_c = static_cast<char>(_i);
	if (_i < 32 || _i > 126)
		_c = 0;
	_d = static_cast<double>(_f);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(1);
}

void Converter::convert_sfloat( const string input ){
	if (input == "+inff")
		_f = std::numeric_limits<float>::infinity();
	else if (input == "-inff")
		_f = -std::numeric_limits<float>::infinity();
	else if (input == "nanf")
		_f = std::numeric_limits<float>::quiet_NaN();
	_d = static_cast<double>(_f);
	_pseudo = true;
}

void Converter::convert_double( const string input ){
	_d = std::stod(input);
	if (_d >= -INT_MAX && _d <= INT_MAX)
	{
		_i = static_cast<int>(_d);
		_c = static_cast<char>(_i);
		if (_i < 32 || _i > 126)
			_c = 0;
	}
	else
		_i_possible = false;
	if (_d >= -FLT_MAX && _d <= FLT_MAX)
		_f = static_cast<double>(_d);
	else
		_f_possible = false;
	if (_d != static_cast<int>(_d))
		_c_possible = false;
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(1);
}

void Converter::convert_sdouble( const string input ){
	if (input == "+inf")
		_d = std::numeric_limits<double>::infinity();
	else if (input == "-inf")
		_d = -std::numeric_limits<double>::infinity();
	else if (input == "nan")
		_d = std::numeric_limits<double>::quiet_NaN();
	_f = static_cast<float>(_d);
	_pseudo = true;
}

void Converter::reset_values( void )
{
	_i = 0;
	_c = 0;
	_f = 0.0f;
	_d = 0.0;
	_pseudo = false;
	_c_possible = true;
	_i_possible = true;
	_f_possible = true;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/



/* ************************************************************************** */