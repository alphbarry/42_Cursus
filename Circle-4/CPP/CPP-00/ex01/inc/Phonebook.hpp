/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:54:29 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 16:54:30 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "../inc/Contact.hpp"

class	Phonebook{
	private:
		Contact	contacts[8];
		int	size;
		int	index;
	public:
		 int	getSize() const;
		 void	addContact(std::string data[5]);
		 void	displayContact(int i);
		 void	displayPhonebook();
		 std::string	searchContacts();
		 Phonebook() : size(0), index(0) {};

};

#endif
