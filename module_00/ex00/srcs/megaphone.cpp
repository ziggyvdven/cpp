/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:00:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/01/05 15:04:00 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv) {
	
	if (argc > 1)
	{
		for (int i = 1; argv[i]; i++)
		{
			for(size_t x = 0; x < strlen(argv[i]); x++)
			{
				if (argv[i][x] > 96 && argv[i][x] < 123)
					argv[i][x] -= 32;
				std::cout << argv[i][x];
			}
		}
		std::cout << std::endl;	
	}
	else 
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}