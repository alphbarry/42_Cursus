/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:22:49 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/30 20:01:52 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("default"), _hitPoints(100), _energyPoints(100), _attackDamage(30) {
	std::cout << "ClapTrap " << _name << " created with default constructor." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hitPoints(100), _energyPoints(100), _attackDamage(30) {
	std::cout << "ClapTrap " << _name << "clap_name created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other){
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ClapTrap " << _name << " copied." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " assigned." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

void	ClapTrap::attack(const std::string& target){
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << "ClapTrap " << _name << " cannot attack!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
	} else {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Remaining hit points: " << _hitPoints << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points! Current hit points: " << _hitPoints << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " cannot be repaired!" << std::endl;
	}
}

int ClapTrap::getHitPoints() {
	return _hitPoints;
}
