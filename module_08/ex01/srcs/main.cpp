/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/02 16:39:23 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int		random_num( void ){
	int random = rand() % 9;
	return (random);
}

int main()
{
	unsigned size;
	
	srand(static_cast<unsigned>(time(nullptr)));
	
	cout << "ENTER max span (N):" << endl;
	std::cin >> size;
	Span sp = Span(size);
	cout << "Vector sp[" << sp.getN() << "] " << sp << endl;
	
  	cout << BOLD <<  "TEST ADDING THREE NUMBERS:" << END << endl;
	try{
		for (int i = 0; i < 3; i++)
		{
			cout << "ENTER number to add to span:" << endl;
			std::cin >> size;
			sp.addNumber(size);
			cout << G << "SUCCES" << END << endl;
			cout << "Vector sp[" << sp.getN() << "] " << sp << endl;
		}
	}
	catch (std::exception& e){
		cout << R << "ERROR [" << e.what() << "]" << END << endl;
	}
	
	cout << BOLD << "TEST ADDING RANGE OF RANDOM NUMBERS (0 - 9):" << END << endl;
	cout << "Please enter size of range to add to span :" << endl;
	std::cin >> size;
	std::vector<int> vec;
	for (unsigned i = 0; i < size; i++)
		vec.push_back(random_num());
	
	try{
		cout << "Trying to add another vector holding " << vec.size() << " values to sp" << endl;
		sp.addRange(vec.begin(), vec.end());	
		cout << G << "SUCCES" << END << endl;
		cout << "Vector sp[" << sp.getN() << "] " << sp << endl;
	}
	catch (std::exception& e){
		cout << R << "ERROR [" << e.what() << "]" << END << endl;
	}

	try{
		cout << "Shortest span in vector: " << sp.shortestSpan() << std::endl; 
	}
	catch (std::exception& e){
		cout << R << "ERROR [" << e.what() << "]" << END << endl;
	}

	try{
		cout << "Longest span in vector: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e){
		cout << R << "ERROR [" << e.what() << "]" << END << endl;
	}
	return (0);
}
