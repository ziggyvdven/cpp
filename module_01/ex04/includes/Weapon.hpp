/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:03:22 by zvandeven         #+#    #+#             */
/*   Updated: 2024/02/29 18:08:21 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>
#include <fstream>

class Weapon
{
	private:
		std::string _type;
	
	public:
		Weapon(std::string name);
		~Weapon( void );
		const std::string& getType(void);
		void setType(std::string newname);
};

#endif
