/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/03 16:09:32 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp" 
#include "stdio.h"

int main()
{
	int a = 2;
	int b = 3;
	swap( a, b );
	cout << "a = " << a << ", b = " << b << endl;
	cout << "min( a, b ) = " << min<int>( a, b ) << endl;
	cout << "max( a, b ) = " << max<int>( a, b ) << endl;
	string c = "chaine1";
	string d = "chaine";
	swap(c, d);
	cout << "c = " << c << ", d = " << d << endl;
	cout << "min( c, d ) = " << ::min<string>( c, d ) << endl;
	cout << "max( c, d ) = " << ::max<string>( c, d ) << endl;
}
