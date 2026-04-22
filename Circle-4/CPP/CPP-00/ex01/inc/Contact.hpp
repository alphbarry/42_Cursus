/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:54:24 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 16:54:26 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <limits>

class	Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	secret;

	public:
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getSecret();
		void	setFirstName(std::string firstName);
		void	setLastName(std::string lastName);
		void	setNickname(std::string nickname);
		void	setPhoneNumber(std::string phoneNumber);
		void	setSecret(std::string secret);
};

#endif
