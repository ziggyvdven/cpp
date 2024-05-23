/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/03 15:29:54 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>
# include <iomanip>

using std::cout;
using std::endl;
using std::exception;
using std::string;

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"


template <typename type>
type const & max(type const &a, type const &b)
{
	return (a > b) ? a : b;
}
template <typename type>
type const & min(type const &a, type const &b)
{
	return (a < b) ? a : b;
}

template <typename type>
void swap(type &a, type &b)
{
	type tmp;
	
	tmp = a;
	a = b;
	b = tmp;
	
	return;
}


#endif /* ******************************************************* WHATEVER_H */