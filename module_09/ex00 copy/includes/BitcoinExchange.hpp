/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/10 16:08:26 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
# include <map>
# include <regex>



using std::cout;
using std::endl;
using std::exception;
using std::string;
using std::getline;

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

# define DATA_FILE "data.csv"

class BitcoinExchange {
public:
	BitcoinExchange ( string & input );
	BitcoinExchange ( BitcoinExchange const & src);
	~BitcoinExchange( void );
	BitcoinExchange &			operator=( BitcoinExchange const & rhs );

	void						exchange( void );
	float						parse_value(string & value);
	int							parse_date(string & date);

private:
	BitcoinExchange ( void );
	std::map<int, float> 		_Map;
	std::ifstream 				_InputData;
	std::ifstream 				_BtcExchange;

};


#endif /* ************************************************ BITCOINEXCHANGE_H */