/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:54:42 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/13 14:37:43 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2){
		Harl harl;

		harl.complain(argv[1]);
	}
	else
		std::cout << "ERROR: NUMBERS OF ARGUMENTS" << std::endl;
	return (0);
}
