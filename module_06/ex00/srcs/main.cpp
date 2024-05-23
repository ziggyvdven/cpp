/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/25 13:30:48 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/converter.hpp" 

size_t	find_counter(string input, char to_find)
{
	size_t count = 0;
	size_t pos = 0;

	pos = input.find(to_find);
	while (pos != string::npos)
	{
		count++;
		pos = input.find(to_find, pos + 1);
	}
	return count;
}

string	literal_type(string input)
{
	if (!input.empty())
	{
		if (input == "-inff" || input == "+inff" || input == "nanf")
			return ("sfloat");
		else if (input == "-inf" || input == "+inf" || input == "nan")
			return ("sdouble");
		if (input.length() > 1)
		{
			for (size_t i = 0; i < input.length(); i++)
			{
				if (!((input[i] >= '0' && input[i] <= '9') || input[i] == '.' || input[i] == 'f' || input[i] == '-'))
					throw (std::invalid_argument("INVALID CHARACTER(S)"));
			}
			if (find_counter(input, 'f') > 1 || find_counter(input, '.') > 1 || find_counter(input, '-') > 1)
				throw (std::invalid_argument("BAD INT/FLOAT/DOUBLE"));
			if (input.find('f') != string::npos)
				return ("float");
			if (input.find('.') != string::npos)
				return ("double");
			else
				return ("int");
		}
		if (input.length() == 1 && (input[0] >= '0' && input[0] <= '9'))
			return ("int");
		else if (input.length() == 1 && (input[0] >= 0 && input[0] <= 127))
			return ("char");
	}
	throw (std::invalid_argument("INVALID ARGUMENT"));
	return ("ERROR");
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string input = argv[1];
		try {
			std::string type = literal_type(input);
			Converter a;
			a.convert(type, input);
			Converter b;
			b = a;
			cout << endl << "SHOWING OBJECT BY ASSINGMENT OPERATOR:" << endl;
			b.convert(type, input);
			Converter c(b);
			cout << endl << "SHOWING OBJECT BY COPY CONSTRUCTOR:" << endl;
			c.convert(type, input);
		}
		catch (std::exception& e)
		{
			cout << R << "ERROR [" << e.what() << "]" << END << endl;
		}
	}
	else
		cout << "INVALID NUMBER OF ARGUMENTS" << endl;
	
	return (0);
}
