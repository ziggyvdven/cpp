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
		std::cout << G << "PmergeMe constructor by parameter called" << END << std::endl;
	};

	PmergeMe ( PmergeMe const & src){
		cout << G << "copy constructor called" << END << endl;
		*this = src;
	};

	~PmergeMe(){
		std::cout << R << "PmergeMe Destructor called" << END << std::endl;
	};

	PmergeMe &				operator=( PmergeMe const & rhs ){
		std::cout << "PmergeMe Copy assignment operator called" << std::endl;
		if ( this != &rhs )
		{
			_con = rhs._con;
			_pairs = rhs._pairs;
		}
		return *this;
	}

	void	test(){
		cout << "Size = " << _con.size() << endl;
	};

	void	sort(){
		int		strangler = 0;

		if (_con.size() % 2 != 0){
			strangler = _con.back();
			_con.pop_back();
		}
		group_pairs(_con, _pairs);
		cout << "[STEP 1] GROUP THE ELEMENTS IN PAIRS OF 2:" << endl;
		for (unsigned i = 0; (i < _con.size() / 2); i++)
			cout << "Pair[" << i << "] [" << _pairs[i].first << " | " << _pairs[i].second << "]" << endl;
		cout << "Strangler = " << strangler << endl;
		sort_pairs(_pairs);
		cout << endl << "[STEP 2] PEFORM COMPARISONS TO DETERMINE THE LARGER OF THE TWO ELEMENTS:" << endl;
		for (unsigned i = 0; (i < _con.size() / 2); i++)
			cout << "Pair[" << i << "] [" << _pairs[i].first << " | " << _pairs[i].second << "]" << endl;
		mergesort(_pairs);
		cout << endl << "[STEP 3] RECURSEVELY SORT THE LARGER ELEMENTS FROM EACH PAIR:" << endl;
		for (unsigned i = 0; (i < _con.size() / 2); i++)
			cout << "Pair[" << i << "] [" << _pairs[i].first << " | " << _pairs[i].second << "]" << endl;
		insertion(_pairs);
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

		int	leftSize = array.size() / 2;
		int rightSize = array.size() - leftSize;
		int i = 0, l = 0, r = 0;

		while (l < leftSize && r < rightSize){
			if (leftArray[l] < rightArray[r]){
				array[i] = leftArray[l];
				i++;
				l++;
			}
			else {
				array[i] = rightArray[r];
				i++;
				r++;
			}
		}
		while (l < leftSize){
			array[i] = leftArray[l];
			i++;
			l++;
		}
		while (r < rightSize){
			array[i] = rightArray[r];
			i++;
			r++;
		}
	}

	void	insertion(P & Pairs){
		T S;
		T Pend;
		T jhal_sequence;
		T index_sequence;

		S.push_back(Pairs[0].second);
		for (unsigned i = 0; i < Pairs.size(); i++)
			S.push_back(Pairs[i].first);
		for (unsigned i = 0; i < S.size(); i++)
			cout << S[i] << " ";
		cout << endl;
		for (unsigned i = 1; i < Pairs.size(); i++)
			Pend.push_back(Pairs[i].second);
		for (unsigned i = 0; i < Pend.size(); i++)
			cout << Pend[i] << " ";
		cout << endl;

		generate_jacob_sequence(jhal_sequence, Pend.size());

		// for (typename T::iterator it = Pend.begin(); it != Pend.end(); ++it)
		// {
			if (jhal_sequence.size() == 1)
			{
				for (int index = (jhal_sequence[0]) - 1; index >= 0; index--)
					index_sequence.push_back(index);
			}
			else
			{
				if (index_sequence.back() < static_cast<int>(Pend.size())){
					for (int index = Pend.size(); index > index_sequence.back(); index--)
						index_sequence.push_back(index);
				}
				while (index != 0)
				{
					
				}
			}
		// }
		cout << "Index Sequence = " << endl;
		for (typename T::iterator it = index_sequence.begin(); it != index_sequence.end(); ++it )
			cout << *it << " ";
		cout << endl;
	}

	int		jacobsthal(int n)
	{
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		return (jacobsthal(n - 1) + 2 * jacobsthal(n -2));
	}

	void 	generate_jacob_sequence(T& jhal_sequence, int size){
		int jacob_index = 3;

		if (size < 3){
			jhal_sequence.push_back(size);
			return;
		}
		while (jacobsthal(jacob_index) < size){
			jhal_sequence.push_back(jacobsthal(jacob_index));
			jacob_index += 1;
		}
	}

private:
	PmergeMe();
	
	T&	_con;
	P& _pairs;

};

#endif /* ****************************************************** PMERGEME_HPP */