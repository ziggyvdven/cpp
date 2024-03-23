/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:43 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/22 19:46:50 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
# define CURE_HPP

# include "./AMateria.hpp"

class Cure : public AMateria
{
	protected:


	public:

		Cure();
		Cure( Cure const & src );
		virtual ~Cure();

		Cure &			operator=( Cure const & rhs );

		std::string const & getType() const;
		virtual Cure* clone() const;
		virtual void use(ICharacter& target);

	private:

};

std::ostream &			operator<<( std::ostream & o, Cure const & i );

#endif /* ************************************************************* Cure_H */