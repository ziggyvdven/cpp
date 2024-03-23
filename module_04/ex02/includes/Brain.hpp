/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:35:53 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/22 13:37:31 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class Brain
{

	public:

		Brain();
		Brain( Brain const & src );
		// Brain(std::string const type);
		~Brain();

		Brain &			operator=( Brain const & rhs );
		void			setIdea(const int i, std::string idea);
		std::string 	getIdea(const int i) const;
		

	protected:

	private:
		std::string _ideas[100];

};

// std::ostream &			operator<<( std::ostream & o, Brain const & i );

#endif /* ********************************************************** BRAIN_H */