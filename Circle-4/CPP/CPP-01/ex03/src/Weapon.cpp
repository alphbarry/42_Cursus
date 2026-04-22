/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:41:21 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 16:41:22 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

void	Weapon::setType(std::string type){
	this->type = type;
}

std::string	Weapon::getType() {
	return this->type;
}

Weapon::Weapon(std::string type) : type(type) {
}

Weapon::~Weapon(void) {
}
