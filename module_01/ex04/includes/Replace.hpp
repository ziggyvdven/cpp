/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:03:22 by zvandeven         #+#    #+#             */
/*   Updated: 2024/03/07 11:31:44 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef REPLACE_HPP
# define REPLACE_HPP

#include <string>
#include <iostream>
#include <fstream>

class Replace
{
	private:
		std::ifstream 	_ifs;
		std::ofstream 	_ofs;
		std::string		_tofind;
		std::string		_replace;
	
	public:
		Replace(std::string s1, std::string s2);
		~Replace( void );
		bool setIfsOfs( const std::string infile);
		bool findandreplace();
		
};

#endif