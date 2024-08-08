/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:55:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/29 15:38:14 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
BitcoinExchange::BitcoinExchange() {
	std::cout << G << "BitcoinExchange Default constructor called" << END << std::endl;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src ){
	std::cout << G << "BitcoinExchange Copy constructor called" << END << std::endl;
	*this = src;
}

BitcoinExchange::BitcoinExchange(string & input) {
	std::cout << G << "BitcoinExchange Default constructor called" << END << std::endl;
	string		line;
	int			date;
	float		value;
	
	_InputData.open(input);
	_BtcExchange.open(DATA_FILE);
	if (!_BtcExchange.good())
		throw(std::runtime_error("UNABLE TO OPEN: " + std::string(DATA_FILE)));
	if (!_InputData.good())
		throw(std::runtime_error("UNABLE TO OPEN: " + input));
	while(getline(_BtcExchange, line)){
		if (line != "date,exchange_rate")
		{
			date = 	std::stoi(line.substr(0, 4) + line.substr(5, 2) + line.substr(8, 2));
			value = std::stof(line.substr(line.find(',') + 1, line.size()));
			_Map[date] = value;
		}
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange(){
	std::cout << R << "BitcoinExchange Destructor called" << END << std::endl;
	if (this->_InputData.is_open())
		this->_InputData.close();
	if (this->_BtcExchange.is_open())
		this->_BtcExchange.close();	
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	std::cout << "BitcoinExchange Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		_Map = rhs._Map;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void				BitcoinExchange::exchange( void ){
	
	string		line;
	int			date;
	float		value, exchange ;		
	
	std::getline(_InputData, line);
	
	while (std::getline(_InputData, line)){
		exchange = 0;
		try{
			size_t delimpos = line.find("|");
			string datestr = line.substr(0, delimpos);
			date = parse_date(datestr);
			if (delimpos != string::npos)
			{
				string valuestr = line.substr(delimpos + 1);
				value = parse_value(valuestr);
				cout << datestr << "=> " << value << " = " ;
				while(date > 20090101)
				{
					if (_Map[date])
					{
						exchange = _Map[date] * value;
						break;
					}
					date--;
				}
				cout << exchange << endl;
			}
		}
		catch (exception &e)
		{
			cout << R << "Error: " << END << e.what() << endl;
		}
	}

}

float			BitcoinExchange::parse_value(string & line){
	
		float		value;
    	std::regex 	templ("^[[:space:]]*[-+]?[0-9]*\\.?[0-9]+[[:space:]]*$");
		
		if (!std::regex_match(line, templ))
			throw(std::runtime_error("Bad input" + line)); 
		value = std::stof(line);
		if (value < 0)
			throw(std::runtime_error("not a positive number.")); 
		if (value > 1000)
			throw(std::runtime_error("too large a number.")); 
		return (value);
}

int				BitcoinExchange::parse_date(string & date){
	
	int			year, month, day;
	
	if (date.size() != 11)
		throw(std::runtime_error("bad input => " + date));
	if (date.at(4) != '-' || date.at(7) != '-')
		throw(std::runtime_error("bad input => " + date));
	year = std::stoi(date.substr(0, 4));
	if (year < 2000 || year > 2025)
		throw(std::runtime_error("bad input => " + date));  
	month = std::stoi(date.substr(5, 6));
	if (month < 1 || month > 12)
		throw(std::runtime_error("bad input => " + date));  
	day = std::stoi(date.substr(8, 9));
	if (day < 1 || day > 31)
		throw(std::runtime_error("bad input => " + date)); 
	return (std::stoi(date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2)));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */