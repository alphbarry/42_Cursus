/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:41:36 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 16:41:50 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
#define	WEAPON_HPP

#include <string>
#include <iostream>

class	Weapon{
	private:
		std::string	type;
	public:
		void	setType(std::string type);
		std::string	getType();
		Weapon(const std::string type);
		~Weapon(void);
};

#endif
