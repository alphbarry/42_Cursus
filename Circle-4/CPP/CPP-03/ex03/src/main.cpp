/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:28:35 by alphbarr          #+#    #+#             */
/*   Updated: 2025/07/02 13:41:54 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"

int main() {
    // 🧍 Crear instancias de cada clase
    ClapTrap    clap("Clap");
    ScavTrap    scav("Scav");
    FragTrap    frag("Frag");
    DiamondTrap diamond("Diamond");

    // 🎯 Ataques
    std::cout << "\n--- 🎯 ATAQUES ---\n" << std::endl;
    clap.attack("target1");
    scav.attack("target2");
    frag.attack("target3");
    diamond.attack("target4");

    // 💥 Daño recibido
    std::cout << "\n--- 💥 DAÑO RECIBIDO ---\n" << std::endl;
    clap.takeDamage(5);
    scav.takeDamage(10);
    frag.takeDamage(15);
    diamond.takeDamage(20);

    // 🔧 Reparaciones
    std::cout << "\n--- 🔧 REPARACIONES ---\n" << std::endl;
    clap.beRepaired(3);
    scav.beRepaired(6);
    frag.beRepaired(9);
    diamond.beRepaired(12);

	// 🧱 Habilidades especiales
    std::cout << "\n--- 🧱 Habilidades especiales ---\n" << std::endl;
    scav.guardGate();           // ScavTrap entra en modo guardia
    frag.highFivesGuys();       // FragTrap pide high five

    // 🧠 Identidad especial de DiamondTrap
    std::cout << "\n--- 🧠 IDENTIDAD ---\n" << std::endl;
    diamond.WhoAmI();

    // ✅ Fin del programa
    std::cout << "\n--- ✅ FIN DEL PROGRAMA ---" << std::endl;
    return 0;
}
