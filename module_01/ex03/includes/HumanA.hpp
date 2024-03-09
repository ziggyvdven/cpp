/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:12:42 by zvandeven         #+#    #+#             */
/*   Updated: 2024/02/29 17:53:02 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "./Weapon.hpp"
# include <string>

class HumanA
{
	private:
		std::string _name;
		Weapon&		_weapon;
		
	public:
		HumanA(std::string human_name, Weapon &weaponREF);
		~HumanA( void );
		void attack(void) const;
};

#endif