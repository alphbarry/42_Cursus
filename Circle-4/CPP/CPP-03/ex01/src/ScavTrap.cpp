/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:10:31 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/29 19:00:21 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "ScavTrap from ClapTrap" << _name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap " << _name << " copied." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap " << _name << " assigned." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destroyed." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << "ScavTrap " << _name << " cannot attack!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	if (_hitPoints > 0) {
		std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode." << std::endl;
	} else {
		std::cout << "ScavTrap " << _name << " cannot enter Gate Keeper mode!" << std::endl;
	}
}
