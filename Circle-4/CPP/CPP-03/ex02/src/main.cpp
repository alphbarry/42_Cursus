/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:28:35 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/25 20:13:50 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int main() {
	ClapTrap claptrap("Clappy");
	claptrap.attack("target1");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);

	ScavTrap scavtrap("Scavvy");
	scavtrap.attack("target2");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(3);
	scavtrap.guardGate();

	return 0;
}
