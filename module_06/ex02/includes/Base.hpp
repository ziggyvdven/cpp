/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:20:22 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/04/12 16:54:16 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <unistd.h>

using std::cout;
using std::endl;
using std::exception;
using std::string;

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define BL "\033[0;34m"
# define R "\033[0;31m"

class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif /* ***************************************************** BASE_HPP */