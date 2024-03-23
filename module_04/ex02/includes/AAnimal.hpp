/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:35:53 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/22 13:36:05 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class AAnimal
{

	public:

		AAnimal();
		AAnimal( AAnimal const & src );
		AAnimal(std::string const type);
		virtual ~AAnimal() = 0;

		AAnimal &		operator=( AAnimal const & rhs );

		std::string 	getType( void ) const;
		virtual void	makeSound( void ) const = 0;

	protected:
		std::string type;

	private:

};

class AWrongAnimal
{

	public:

		AWrongAnimal();
		AWrongAnimal( AWrongAnimal const & src );
		AWrongAnimal(std::string const type);
		virtual ~AWrongAnimal() = 0;

		AWrongAnimal &		operator=( AWrongAnimal const & rhs );

		std::string 	getType( void ) const;
		void			makeSound( void ) const;

	protected:
		std::string type;

	private:

};

std::ostream &			operator<<( std::ostream & o, AAnimal const & i );

#endif /* ********************************************************** ANIMAL_H */