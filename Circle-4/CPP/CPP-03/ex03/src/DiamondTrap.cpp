/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:54:06 by alphbarr          #+#    #+#             */
/*   Updated: 2025/07/02 13:36:08 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): FragTrap("default_clap_name"), ScavTrap("default_clap_name"), _name("default") {
	std::cout << "DiamondTrap " << _name << " created with default constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"),FragTrap(name), ScavTrap(name){
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " created with name: " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other){
	std::cout << "DiamondTrap " << _name << " copied." << std::endl; 
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		this->_name = other._name;
	}
	std::cout << "DiamondTrap " << _name << " assigned." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << _name << " destroyed." << std::endl;
}

void DiamondTrap::WhoAmI(){
	if (_hitPoints < 0)
		std::cout << "Can't identify myself, I am dead." << std::endl;
	else{
		std::cout << "My name is " << _name << std::endl;
		std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
	}
}

void	DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}
