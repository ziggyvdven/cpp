/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:31:14 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/20 16:43:27 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Dog.hpp"

class Cat : public Animal
{

	public:

		Cat();
		Cat( Cat const & src );
		~Cat();

		Cat &			operator=( Cat const & rhs );

		std::string 	getType() const;
		virtual void	makeSound( void ) const;

	protected:


	private:

};

class WrongCat : public WrongAnimal
{

	public:

		WrongCat();
		WrongCat( WrongCat const & src );
		~WrongCat();

		WrongCat &			operator=( WrongCat const & rhs );

		std::string 	getType() const;
		virtual void	makeSound( void ) const;

	protected:


	private:

};

std::ostream &			operator<<( std::ostream & o, Cat const & i );

#endif /* ************************************************************* CAT_H */