#include "../inc/FragTrap.hpp"
#include <ostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap from ClapTrap " << name << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap " << this->_name << " copied." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap " << _name << " assigned." << std::endl;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destroyed." << std::endl;
}

void FragTrap::attack(const std::string &target){
	if (_energyPoints > 0 && _hitPoints > 0){
		std::cout << "FragTrap " << _name << " attacks " << target << " with " << _attackDamage << " of damage" << std::endl;
	}
	else{
		std::cout << "FragTrap " << _name << " cannot attack" << std::endl;
	}	
}

void FragTrap::highFivesGuys(){
	if (_hitPoints > 0)
		std::cout << "I love Five Guys." << std::endl;
	else
		std::cout << "Not alive for eat this burguer" << std::endl;
}
