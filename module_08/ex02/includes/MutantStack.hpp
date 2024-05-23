/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/15 16:46:38 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <deque>
# include <stack>
# include <list>


using std::cout;
using std::endl;
using std::exception;
using std::string;

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T>{
public:
						MutantStack ( void ) : std::stack<T>() {};
						MutantStack ( MutantStack const & src){*this = src;};
						~MutantStack( void ){};

	MutantStack &		operator=( MutantStack const & rhs ){
			std::stack<T>::operator=(rhs);
			return (*this);
	};

	typedef typename Container::iterator	iterator;

	iterator	begin(void) {return this->c.begin();}
	iterator	end(void) {return this->c.end();}	
};

// std::ostream &			operator<<( std::ostream & o, MutantStack const & i );

#endif /* ***************************************************** MUTANTSTACK_H */