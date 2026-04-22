/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:41:26 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 16:41:27 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) : name(name){
	std::cout << "HumanB:" << name << " created with "<< std::endl;
}

HumanB::~HumanB(void){
	std::cout << "HumanB:" << name << " destroyed" << std::endl;
}

void	HumanB::attack(){
	std::cout << "HumanB:" << name << " attacks with " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}
