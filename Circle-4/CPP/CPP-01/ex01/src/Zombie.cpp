/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:42:28 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/10 13:09:43 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() {
	std::cout << "Zombie created." << std::endl;
}

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << "Zombie " << name << " created." << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie " << this->name << " destroyed." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->name = name;
}
