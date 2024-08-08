/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:55:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/06/05 15:43:12 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
RPN::RPN() {
	// std::cout << G << "RPN Default constructor called" << END << std::endl;
}

RPN::RPN(string const & input): _InputStr(input) {
	// std::cout << G << "RPN constructor by parameter called" << END << std::endl;
	
}

RPN::RPN( const RPN & src ){
	// std::cout << G << "RPN Copy constructor called" << END << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN(){
	// std::cout << R << "RPN Destructor called" << END << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	// std::cout << "RPN Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		_Stack = rhs._Stack;
		_InputStr = rhs._InputStr;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int					RPN::calculate(){
	unsigned 		operants = 0, operators = 0;
	
	for(string::iterator it = _InputStr.begin(); it != _InputStr.end(); ++it)
	{
		if (*it >= '0' && *it <= '9'){
			_Stack.push(*it - '0');
			operants++;
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/'){
			if (operants > 1 && operators < operants - 1)
				math(*it);
			else
				throw(std::runtime_error("Bad input: " + _InputStr));
			operators++;
		}
		else
			throw(std::runtime_error("Bad input: " + _InputStr));
		if (it != _InputStr.end() - 1){
			++it;
			if (*it != ' '){
				throw(std::runtime_error("Bad input: " + _InputStr));
			}
		}
	}
	if (operators != operants - 1)
		throw(std::runtime_error("INVALID ENTRY"));
	cout << _Stack.top() << endl;
	return (0);
}

void			RPN::math(char const & c){
	
	int op1 = 0 , op2 = 2 , result = 0;
	
	op2 = _Stack.top();
	_Stack.pop();
	op1 = _Stack.top();
	_Stack.pop();
	switch (c){
		case '+':
			result = op1 + op2;
			break;
		case '-':
			result = op1 - op2;
			break;
		case '*':
			result = op1 * op2;
			break;
		case '/':
			if (op2 == 0)
				throw(std::runtime_error("devision by zero"));
			result = op1 / op2;
			break;
		default:
			throw(std::runtime_error("invalid operator"));
	}
	if (result < 0)
		throw(std::runtime_error("OUT OF BOUNDS"));
	_Stack.push(result);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */