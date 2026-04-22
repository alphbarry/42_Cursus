/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:42:33 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/10 13:07:28 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie{
	private:
		std::string	name;
	public:
		void	announce(void);
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void	setName(std::string name);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
#endif
