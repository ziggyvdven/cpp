/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:43 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/05/29 17:42:26 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# define BOLD "\033[1;37m"
# define END "\033[0m"
# define G "\033[0;32m"
# define B "\033[0;34m"
# define R "\033[0;31m"

class ICharacter;

class AMateria
{
	protected:
		std::string			type;

	public:

		AMateria();
		AMateria( AMateria const & src );
		AMateria(std::string const & type);
		virtual ~AMateria();

		AMateria &			operator=( AMateria const & rhs );

		std::string const & getType() const;
		virtual AMateria* 	clone() const = 0;
		virtual void 		use(ICharacter& target);

	private:
	

};

extern AMateria* g_floor[100];

std::ostream &			operator<<( std::ostream & o, AMateria const & i );

#endif /* ******************************************************** AMATERIA_H */