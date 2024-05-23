/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/23 17:15:55 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	sort_containers(std::deque<int> & deq, std::vector<int> & vec, int argc)
{
	string names[2] = {"deque", "vector"};
	std::deque< std::pair <int, int> > d_pairs;
	std::vector< std::pair <int, int> > v_pairs;
	
	PmergeMe<std::vector<int>, std::vector< std::pair <int, int> > > vector(vec, v_pairs);
	PmergeMe<std::deque<int>, std::deque< std::pair <int, int> > > deque(deq, d_pairs);
	
	cout << "Before:  ";
	for (size_t i = 0; i < deq.size(); i++)
		cout << deq[i] << " ";
	cout << endl;
	struct timeval start, end;
	for (int i = 0; i < 2; i++){
		gettimeofday(&start, nullptr);
		if (i == 0){
			vector.sort();
		}
		// else
		// 	deque.sort();
		gettimeofday(&end, nullptr);
		if (i == 0){
			cout << "after:  ";
			for (size_t i = 0; i < vec.size(); i++)
				cout << vec[i] << " ";
			cout << endl;
		}
		double duration = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
		cout << std::fixed << std::setprecision(5);
		cout << "Time to process a range of " << argc - 1 << " elements with std::" << names[i] << " : " << duration << " us" << endl; 
	}
	return (0);
}


int main(int argc, char** argv)
{
	if (argc > 2)
	{
		std::deque<int> 	deq;
		std::vector<int> 	vec;
		long				num;

		for (int i = 1; i < argc; i++)
		{
			char* end;
			num = std::strtol(argv[i], &end, 10);
			if (num <= 0 || num > INT_MAX)
			{
				std::cerr << R << "ERROR [PLEASE ENTER ONLY POSITIVE INTEGER VALUES]" << END << endl;
				return (1);
			}
			if (*end != '\0') {
            	std::cerr << R << "ERROR [ " << argv[i] << " IS NOT VALID]" << END << std::endl;
            	return 1;
			}
			deq.push_back(num);
			vec.push_back(num);
		}
		sort_containers(deq, vec, argc);
	}
	else
	{
		std::cerr << "ERROR [NOT ENOUGH ARGUMENTS]" << endl;
		return (1);
	}
	return (0);
}
