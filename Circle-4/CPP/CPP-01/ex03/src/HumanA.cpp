/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:15:12 by alpha             #+#    #+#             */
/*   Updated: 2025/06/09 16:41:31 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name) {
	std::cout << "HumanA: " << name << " created with " << weapon.getType() << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << "HumanA: " << name << " destroyed" << std::endl;
}

void	HumanA::attack(){
	std::cout << "HumanA:" << name << "attacks with " << weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon weapon){
	this->weapon = weapon;
}
