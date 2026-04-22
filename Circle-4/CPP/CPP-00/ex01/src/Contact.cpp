/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:53:39 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 16:53:40 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

std::string Contact::getFirstName() {
	return firstName;
}

std::string Contact::getLastName() {
	return lastName;
}

std::string Contact::getNickname() {
	return nickname;
}

void Contact::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Contact::setNickname(std::string nickname) {
	this->nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

std::string Contact::getPhoneNumber() {
	return phoneNumber;
}

void Contact::setSecret(std::string Secret) {
	this->secret = Secret;
}

std::string Contact::getSecret() {
	return secret;
}
