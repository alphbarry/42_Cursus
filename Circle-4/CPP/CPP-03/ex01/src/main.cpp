/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:28:35 by alphbarr          #+#    #+#             */
/*   Updated: 2025/07/02 13:52:40 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int main() {
	// 🧍 Crear instancias
    ClapTrap claptrap("Clappy");
    ScavTrap scavtrap("Scavvy");

    std::cout << "\n=== 🤖 INICIO DEL COMBATE ===\n" << std::endl;

    std::cout << "--- 🎯 ATAQUES INICIALES ---" << std::endl;
    claptrap.attack("DummyBot");
    scavtrap.attack("TargetBot");

    std::cout << "\n--- 💥 DAÑOS RECIBIDOS ---" << std::endl;
    claptrap.takeDamage(3);   // HP reduce
    scavtrap.takeDamage(5);

    std::cout << "\n--- 🔧 PRIMERAS REPARACIONES ---" << std::endl;
    claptrap.beRepaired(2);   // HP increase
    scavtrap.beRepaired(3);

    std::cout << "\n--- 🎯 NUEVOS ATAQUES ---" << std::endl;
    claptrap.attack("DummyBot");
    scavtrap.attack("TargetBot");

    std::cout << "\n--- 💣 MÁS DAÑO ---" << std::endl;
    claptrap.takeDamage(6);   // Puede llegar a 0 HP
    scavtrap.takeDamage(4);

    std::cout << "\n--- 🔧 SEGUNDAS REPARACIONES ---" << std::endl;
    claptrap.beRepaired(5);   // ¿Sobrevive?
    scavtrap.beRepaired(7);

    std::cout << "\n--- 🛡️ HABILIDADES ESPECIALES ---" << std::endl;
    scavtrap.guardGate();     // Modo guardia

    std::cout << "\n=== ✅ FIN DEL COMBATE ===" << std::endl;
    return 0;
}
