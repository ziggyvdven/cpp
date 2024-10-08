/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/16 13:52:17 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
# include <vector>
# include <deque>
# include <ctime>
# include <unistd.h>
# include <sys/time.h>
# include <utility>

using std::cout;
using std::cerr;
using std::endl;
using std::exception;
using std::string;

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

template< typename T , typename P >
class PmergeMe {
public:

	PmergeMe(T & container, P & pairs_container) : _con(container), _pairs(pairs_container) {
	};

	PmergeMe ( PmergeMe const & src){
		*this = src;
	};

	~PmergeMe(){
	};

	PmergeMe &				operator=( PmergeMe const & rhs ){
		if ( this != &rhs )
		{
			_con = rhs._con;
			_pairs = rhs._pairs;
		}
		return *this;
	}

	void	sort(){
		int		strangler = -1;

		if (_con.size() % 2 != 0){
			strangler = _con.back();
			_con.pop_back();
		}
		group_pairs(_con, _pairs);
		sort_pairs(_pairs);
		mergesort(_pairs);
		insertion(_pairs);
		if (strangler != -1){
				typename T::iterator insertion_point = std::lower_bound(_con.begin(), _con.end(), strangler);
				_con.insert(insertion_point, strangler);
		}
	};

	void	group_pairs(T & Array, P & Pairs){
		int lenght = Array.size();
		int i = 0;

		while (i < lenght){
			Pairs.push_back(std::make_pair(Array[i], Array[i + 1]));
			i += 2;
		}
	}

	void	sort_pairs(P & Pairs){
		int lenght = Pairs.size();

		for (int i = 0; i < lenght; i++){
			if (Pairs[i].first < Pairs[i].second)
				std::swap(Pairs[i].first, Pairs[i].second);
		}
	}

	void	mergesort(P & Pairs){
		int length = Pairs.size();
		if (length <= 1)
			return;
		int middle = length / 2;
		P leftArray;
		P rightArray;

		int i = 0;
		int j = 0;

		for (; i < length; i++){
			if (i < middle){
				leftArray.push_back(Pairs[i]);
			}
			else {
				rightArray.push_back(Pairs[i]);
				j++;
			}
		}
		mergesort(leftArray);
		mergesort(rightArray);
		merge(leftArray, rightArray, Pairs);
	}

	void	merge(P & leftArray, P & rightArray, P & array){

		int		leftSize = array.size() / 2;
		int 	rightSize = array.size() - leftSize;
		int 	i = 0, l = 0, r = 0;

		while (l < leftSize && r < rightSize){
			if (leftArray[l] < rightArray[r])
				array[i++] = leftArray[l++];
			else 
				array[i++] = rightArray[r++];
		}
		while (l < leftSize)
			array[i++] = leftArray[l++];
		while (r < rightSize)
			array[i++] = rightArray[r++];
	}

	void	insertion(P & Pairs){

		T 	S;
		T 	Pend;
		T 	index_sequence;

		for (size_t i = 0; i < Pairs.size(); i++){
			S.push_back(Pairs[i].first);
			Pend.push_back(Pairs[i].second);
		}
		S.insert(S.begin(), Pend.front());
		generate_index_sequence(index_sequence, Pend.size());
		for (size_t i = 1; i < index_sequence.size(); i++){
			typename T::iterator insertion_point = std::lower_bound(S.begin(), S.end(), Pend[index_sequence[i]]);
			S.insert(insertion_point, Pend[index_sequence[i]]);
		}
		_con = S;
	}

	int		jacobsthal(int n){

		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		return (jacobsthal(n - 1) + 2 * jacobsthal(n -2));
	}

	void  	generate_index_sequence(T& index_sequence, size_t size){

		int jacob_index = 0, index = 0;
		T 	jhal_sequence;

		while (jacobsthal(jacob_index) < static_cast<int>(size)){
			jhal_sequence.push_back(jacobsthal(jacob_index));
			jacob_index += 1;
		}
		for (size_t i = 1; i < jhal_sequence.size(); i++){
			index = jhal_sequence[i];
			while (index > jhal_sequence[i - 1] && index >= 0)
			{
				index_sequence.push_back(index - 1);
				index--;
			}
		}
		if (jhal_sequence.back() < static_cast<int>(size))
		{
			index = static_cast<int>(size);
			while (index > jhal_sequence.back())
			{
				index_sequence.push_back(index - 1);
				index--;
			}
		}
	}

private:
	PmergeMe();
	
	T&	_con;
	P& _pairs;
};

#endif /* ****************************************************** PMERGEME_HPP */