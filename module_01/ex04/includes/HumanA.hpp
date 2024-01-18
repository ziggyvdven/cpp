/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:12:42 by zvandeven         #+#    #+#             */
/*   Updated: 2024/01/18 16:48:44 by zvan-de-         ###   ########.fr       */
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
		void attack(void);
};

#endif