/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:07:54 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/15 17:04:56 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

int		random_num( void ){
	int random = rand() % 9;
	return (random);
}

int main()
{
	MutantStack<int> mstack;
	mstack.push(5); 
	mstack.push(17);
	std::cout << mstack.top() << std::endl; 
	
	mstack.pop();
	
	std::cout << mstack.size() << std::endl;
	mstack.push(3); 
	mstack.push(5); 
	mstack.push(737); //[...] mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin(); 
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	
	while (it != ite) {
		std::cout << *it << std::endl;
	++it; }
	std::stack<int> s(mstack);

	std::cout << std::endl;

	std::list<int> list1;
	list1.push_back(5); 
	list1.push_back(17);
	std::cout << list1.back() << std::endl; 
	
	list1.pop_back();
	
	std::cout << list1.size() << std::endl;
	list1.push_back(3); 
	list1.push_back(5); 
	list1.push_back(737); //[...] list1.push(0);
	
	std::list<int>::iterator it1 = list1.begin(); 
	std::list<int>::iterator ite1 = list1.end();
	++it1;
	--it1;
	
	while (it1 != ite1) {
		std::cout << *it1 << std::endl;
	++it1; }
	std::list<int> s1(list1); 
	return 0;
}
