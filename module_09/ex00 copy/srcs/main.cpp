/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/06/13 16:13:45 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <map>

int main()
{
	std::map<string, string> map;

	map["test"] = "test1";
	cout << map["test"] << endl;

	
	return (0);
}
