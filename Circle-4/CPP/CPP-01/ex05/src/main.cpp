/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:40:21 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 18:12:03 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int	main(){
	Harl	harl;

	std::cout << GRAY << "Harl is ready to complain." << std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	std::cout << GRAY << "Harl has finished complaining." << std::endl;
	return (0);
}
