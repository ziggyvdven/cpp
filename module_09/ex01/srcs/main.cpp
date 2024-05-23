/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/16 15:37:26 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		try{
		RPN maths(argv[1]);
		maths.calculate();	
		}
		catch (exception &e)
		{
			cout << R << "ERROR[" << e.what() << "]." << endl;
		}
	}
	else
	{
		cout << "ERROR [NOT ENOUGH ARGUMENTS]" << endl;
		return (1);
	}
	return (0);
}
