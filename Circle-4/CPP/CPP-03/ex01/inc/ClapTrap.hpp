/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:19:46 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/29 18:59:41 by alpha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap{
	protected:
		std::string	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();
};

#endif
