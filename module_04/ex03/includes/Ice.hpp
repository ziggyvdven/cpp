/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:43 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/22 19:46:47 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICE_HPP
# define ICE_HPP

# include "./AMateria.hpp"

class Ice : public AMateria
{
	protected:


	public:

		Ice();
		Ice( Ice const & src );
		virtual ~Ice();

		Ice &			operator=( Ice const & rhs );

		std::string const & getType() const;
		virtual Ice* clone() const;
		virtual void use(ICharacter& target);

	private:

};

std::ostream &			operator<<( std::ostream & o, Ice const & i );

#endif /* ************************************************************* ICE_H */