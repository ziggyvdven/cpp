/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/02 17:08:42 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <array>
# include <map>
# include <algorithm>


using std::cout;
using std::endl;
using std::exception;
using std::string;

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

template< typename T>
void easyfind(T &con, int i)
{
	typename T::iterator p;

	p = std::find (con.begin(), con.end(), i);
	if (p != con.end())
		cout << "First occurenct of " << i << " at position " << std::distance(con.begin(), p) << " of the container." << endl;
	else
		throw (std::runtime_error("VALUE NOT FOUND IN CONTAINER"));
	return;
}


#endif /* ******************************************************** EASYFIND_H */