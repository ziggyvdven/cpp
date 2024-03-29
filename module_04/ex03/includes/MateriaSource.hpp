/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:10:43 by zvan-de-          #+#    #+#             */
/*   Updated: 2024/03/28 15:47:21 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIALSOURCE_HPP
# define MATERIALSOURCE_HPP

# include "./AMateria.hpp"

/* Default size of memory */
# ifndef	S_MEMORY
#  define	S_MEMORY	4
# endif	

/* Default number of materials */
# ifndef	N_MATERIALS
#  define	N_MATERIALS	2
# endif

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
	protected:
		AMateria*	memory[4];

	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		~MateriaSource();

		MateriaSource &			operator=( MateriaSource const & rhs );
		virtual void 			learnMateria(AMateria*);
		virtual AMateria* 		createMateria(std::string const & type);
	
	private:
		std::string _materias[N_MATERIALS];
};


#endif /* ************************************************** MATERIASOURCE_H */