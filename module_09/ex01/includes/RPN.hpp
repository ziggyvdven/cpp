/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/16 13:52:17 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
# include <stack>
# include <deque>
# include <regex>

using std::cout;
using std::endl;
using std::exception;
using std::string;

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"


class RPN {
public:
	RPN (string const &input);
	RPN ( RPN const & src);
	~RPN( void );

	RPN &		operator=( RPN const & rhs );

	int 		calculate();
	void		math(char const & c);


private:
	RPN ( void );
	string				_InputStr;
	std::stack<int>		_Stack;

};

#endif /* ************************************************ RPN_HPP */