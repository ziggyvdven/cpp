/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:12:42 by zvandeven         #+#    #+#             */
/*   Updated: 2024/01/15 17:20:57 by zvandeven        ###   ########.fr       */
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
		HumanA(std::string humanname, Weapon &weaponREF);
		~HumanA();
		void attack(void);
};

#endif