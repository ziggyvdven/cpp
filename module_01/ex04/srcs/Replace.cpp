/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:32:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/07 11:24:48 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Replace.hpp"

Replace::Replace(std::string s1, std::string s2) : _tofind(s1), _replace(s2) 
{
}

Replace::~Replace(void){
	if (this->_ofs.is_open())
		this->_ofs.close();
	if (this->_ifs.is_open())
		this->_ifs.close();
}

bool Replace::setIfsOfs( const std::string infile)
{
	if (infile.empty() || this->_ifs.is_open())
		return (false);
	else
	{
		this->_ifs.open(infile.c_str());
		if (this->_ifs.good() == false)
			return (false);
	}
	if (this->_ofs.is_open())
		return (false);
	else
	{
		this->_ofs.open(infile + ".replace");
		if (this->_ifs.good() == false)
			return (false);
	}
	return (true);
}

bool Replace::findandreplace( void ) 
{
	std::string input = "";
	
	if (!this->_ifs.good() || !this->_ofs.good() || this->_tofind == this->_replace)
		return (false);
	while(1)
	{
		int			start = 0;
		getline( this->_ifs, input );
		while (1)
		{
			if ((input.find(this->_tofind, start) != std::string::npos))
			{
				start = input.find(this->_tofind, start);
				input.erase(start, this->_tofind.length());
				input.insert(start, this->_replace);
				start += this->_replace.length();
			}
			else
				break;
		}
		this->_ofs << input;
		if (this->_ifs.eof() == true)
			break ;
		this->_ofs << std::endl;
		input.clear();
	}
	return (true);
}
