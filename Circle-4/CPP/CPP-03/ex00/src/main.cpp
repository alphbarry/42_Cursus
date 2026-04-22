/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:28:35 by alphbarr          #+#    #+#             */
/*   Updated: 2025/07/02 13:48:50 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main() {
	 // 🧍 Crear una instancia de ClapTrap
    ClapTrap claptrap("Sambu");

    std::cout << "\n=== 🤖 INICIO DEL COMBATE ===\n" << std::endl;

    std::cout << "--- 🎯 ATAQUES INICIALES ---" << std::endl;
    claptrap.attack("Mussá");
    claptrap.attack("Izzy");

    std::cout << "\n--- 💥 PRIMEROS DAÑOS ---" << std::endl;
    claptrap.takeDamage(4);  // 10 -> 6 HP
    claptrap.takeDamage(2);  // 6 -> 4 HP

    std::cout << "\n--- 🔧 PRIMERA REPARACIÓN ---" << std::endl;
    claptrap.beRepaired(3);  // 4 -> 7 HP

    std::cout << "\n--- 🎯 CONTRAATAQUES ---" << std::endl;
    claptrap.attack("Kalilu");
    claptrap.attack("Moussa");

    std::cout << "\n--- 💥 DAÑO CRÍTICO ---" << std::endl;
    claptrap.takeDamage(8);  // 7 -> 0 HP (muere)

    std::cout << "\n--- 🔧 INTENTO DE REPARACIÓN TRAS MUERTE ---" << std::endl;
    claptrap.beRepaired(4);  // No debería funcionar si está a 0 HP

    std::cout << "\n=== 🏁 FIN DEL COMBATE ===" << std::endl;

    return 0;
}
