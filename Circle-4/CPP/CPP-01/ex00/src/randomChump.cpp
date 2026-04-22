/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:42:45 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/10 13:06:11 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

void	randomChump(std::string name) {
	Zombie	zombie(name);
	zombie.announce();
}
