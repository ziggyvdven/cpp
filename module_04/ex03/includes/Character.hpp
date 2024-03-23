/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:43 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/22 20:03:18 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "./AMateria.hpp"

/* Default number of materials */
# ifndef	N_MATERIALS
#  define	N_MATERIALS	2
# endif

/* Default size of inventory */
# ifndef	S_INVENTORY
#  define	S_INVENTORY	4
# endif	

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0; 
		virtual void 				equip(AMateria* m) = 0;
		virtual void 				unequip(int idx) = 0;
		virtual void 				use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
	protected:
		std::string name;
		AMateria*	inventory[S_INVENTORY];

	public:

		Character();
		Character( Character const & src );
		Character(std::string const & type);
		~Character();

		Character &				operator=( Character const & rhs );
		std::string const & 	getName() const;
		virtual void 			equip(AMateria* m);
		virtual void 			unequip(int idx);
		virtual void 			use(int idx, ICharacter& target);

	private:
		std::string _materias[N_MATERIALS];
};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */