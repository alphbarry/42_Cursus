/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:41:57 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 16:41:58 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanA{
	private:
		Weapon&		weapon;
		std::string	name;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void	attack(void);
		void	setWeapon(Weapon weapon);
};
