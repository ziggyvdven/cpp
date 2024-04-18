/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/17 20:43:39 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cfloat>
# include <climits> 

using std::cout;
using std::endl;
using std::exception;
using std::string;

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class Converter
{

	public:

		Converter();
		Converter( Converter const & src );
		~Converter();

		Converter &		operator=( Converter const & rhs );

		void			convert(const string type, string literal);

		void 			convert_char( string input );
		void 			convert_int( string input );
		void 			convert_float( string input );
		void 			convert_sfloat( string input );
		void 			convert_double( string input );
		void 			convert_sdouble( string input );

		void			print_conversion( void );

	private:

		int				_i;
		char			_c;
		float			_f;
		double			_d;
		string			_literals[6];
		bool			_pseudo;
		bool			_c_possible;
		bool			_i_possible;
		bool			_f_possible;
		void 			(Converter::*_func[6])(string input);
		
};

#endif /* ******************************************************* CONVERTER_H */