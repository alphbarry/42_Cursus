/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:42:20 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/10 13:08:39 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name){
	Zombie*	horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name); ;
	}
	return horde;
}
