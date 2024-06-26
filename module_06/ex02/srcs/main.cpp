/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/17 20:39:05 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp" 
#include <stdio.h>


int main( void )
{
	Base* a = generate();
	Base& b = *a;
	cout << "identify(Base* ptr) gives: ";
	identify(a);
	cout << "identify(Base& ref) gives: ";
	identify(b);
	delete(a);
	return (0);
}
