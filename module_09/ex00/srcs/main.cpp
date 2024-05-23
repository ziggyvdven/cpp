/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/10 12:55:38 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		string input(argv[1]);
		if (input.empty())
			cout << "ERROR [INPUT EMPTY]" << endl;
		BitcoinExchange btc(input);
		btc.exchange();
	}
	else
	{
		cout << "ERROR [NOT ENOUGH ARGUMENTS]" << endl;
		return (1);
	}
	return (0);
}
