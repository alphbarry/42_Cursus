/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:40:21 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/10 13:45:13 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int	transform_format(char *av){
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (av == NULL)
		return (0);
	for (int i = 0; av[i]; i++)
		if (levels[i] == av)
			return (i);
	return (0);
}

void	switch_harl(char *av, Harl& harl){
	switch(transform_format(av)){
		case 1:
			harl.complain("DEBUG");
			break;
		case 2:
			harl.complain("INFO");
			break;
		case 3:
			harl.complain("WARNING");
			break;
		case 4:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

int	main(int ac, char **av){
	Harl	harl;

	if (ac != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		switch_harl(av[1], harl);
	return (0);
}
