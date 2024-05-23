/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/26 12:07:35 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <algorithm>
#include <stack>

int		random_num( void ){
	int random = rand() % 9;
	return (random);
}

int main(int argc, char** argv)
{
	srand(static_cast<unsigned>(time(nullptr)));
	if (argc == 2)
	{
		std::list<int>		lst1;
		for (int i = 0; i < 10; i++)
			lst1.push_back(random_num());
		lst1.push_back(42);

		std::array<int, 11> 	arr1;
		for (int i = 0; i < 10; i++)
			arr1[i] = random_num();
		arr1[10] = 42;
		
		std::vector<int> vec1;
		for (int i = 0; i < 10; i++)
			vec1.push_back(random_num());
		vec1.push_back(42);

		std::deque<int> deq1;
		for (int i = 0; i < 10; i++)
			deq1.push_back(random_num());
		deq1.push_back(42);
		
		try {
			cout << BOLD <<  "Trying to find " << argv[1] << " in LIST container:" << END << endl;
			easyfind(lst1, atoi(argv[1]));
		}
		catch (std::runtime_error e){
			cout << R << "LIST[" << e.what() << "]" << END << endl;
		}
		
		try {
			cout << BOLD << "Trying to find " << argv[1] << " in ARRAY container:" << END << endl;
			easyfind(arr1, atoi(argv[1]));
		}
		catch (std::runtime_error e){
			cout << R << "ARRAY[" << e.what() << "]" << END << endl;
		}

		try {
			cout << BOLD << "Trying to find " << argv[1] << " in VECTOR container:" << END << endl;
			easyfind(vec1, atoi(argv[1]));
		}
		catch (std::runtime_error e){
			cout << R << "VECTOR[" << e.what() << "]" << END << endl;
		}

		try {
			cout << BOLD << "Trying to find " << argv[1] << " in DEQUE container:" << END << endl;
			easyfind(deq1, atoi(argv[1]));
		}
		catch (std::runtime_error e){
			cout << R << "DEQUE[" << e.what() << "]" << END << endl;
		}
	}
	return (0);
}
