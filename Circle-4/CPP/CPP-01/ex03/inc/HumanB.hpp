/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:41:53 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 16:41:54 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class	HumanB{
	private:
		Weapon*		weapon;
		std::string	name;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	attack(void);
		void	setWeapon(Weapon &weapon);
};
