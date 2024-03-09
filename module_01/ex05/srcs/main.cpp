/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:54:42 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/07 13:57:50 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Harl.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		Harl harl;

		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		std::cout << std::endl;
		harl.complain("ERR");
		harl.complain("ERRORR");
	}
	return (0);
}
