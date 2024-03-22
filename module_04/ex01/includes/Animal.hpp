/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:35:53 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/20 16:54:26 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class Animal
{

	public:

		Animal();
		Animal( Animal const & src );
		Animal(std::string const type);
		virtual ~Animal();

		Animal &		operator=( Animal const & rhs );

		std::string 	getType( void ) const;
		virtual void	makeSound( void ) const;

	protected:
		std::string type;

	private:

};

class WrongAnimal
{

	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		WrongAnimal(std::string const type);
		virtual ~WrongAnimal();

		WrongAnimal &		operator=( WrongAnimal const & rhs );

		std::string 	getType( void ) const;
		void			makeSound( void ) const;

	protected:
		std::string type;

	private:

};

std::ostream &			operator<<( std::ostream & o, Animal const & i );

#endif /* ********************************************************** ANIMAL_H */