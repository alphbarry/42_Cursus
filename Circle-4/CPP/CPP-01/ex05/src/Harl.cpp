/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:40:37 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 18:09:43 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl() {
	std::cout << "Harl created." << std::endl;
}

Harl::~Harl() {
	std::cout << "Harl destroyed." << std::endl;
}

void	Harl::debug(){
	std::cout << MAGENTA << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(){
	std::cout << MAGENTA << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You don’t put enough!";
	std::cout << " If you want to have a burger without bacon, you should just go to McDonald's!" << std::endl;
}

void	Harl::warning(){
	std::cout << YELLOW << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming here for years!" << std::endl;
}

void	Harl::error(){
	std::cout << RED << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level){
	void (Harl::*funcs[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*funcs[i])();
			return;
		}
	}
	std::cout << GRAY << "[ Probably complaining about insignificant problems ]" << std::endl;
}
