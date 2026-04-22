/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:53:44 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 16:53:45 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"
#include <iomanip>

int Phonebook::getSize() const {
	return size;
}

int ft_atoi(const std::string& str) {
	int res = 0;
	for (size_t i = 0; i < str.length(); ++i) {
		char c = str[i];
		if (c < '0' || c > '9') {
			return -1;
		}
		res = res * 10 + (c - '0');
	}
	return res;
}


std::string formatField(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
}

void	Phonebook::addContact(std::string* data){

	if (index >= 8)
		index = 0;
	contacts[index].setFirstName(data[0]);
	contacts[index].setLastName(data[1]);
	contacts[index].setNickname(data[2]);
	contacts[index].setPhoneNumber(data[3]);
	contacts[index].setSecret(data[4]);
	index++;
	if (size < 8)
		size++;
}

void	Phonebook::displayContact(int i){
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|" << std::setw(10) << i
	 << "|" << formatField(contacts[i].getFirstName())
	 << "|" << formatField(contacts[i].getLastName())
	 << "|" << formatField(contacts[i].getNickname())
	 << "|" << std::endl;
}

void	Phonebook::displayPhonebook(){
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < size; i++) {
		std::cout << "|" << std::setw(10) << i
             << "|" << formatField(contacts[i].getFirstName())
             << "|" << formatField(contacts[i].getLastName())
             << "|" << formatField(contacts[i].getNickname())
             << "|" << std::endl;
    }
}

std::string Phonebook::searchContacts() {
	std::string input;
    int index;

	displayPhonebook();

    if (size == 0) {
		std::cout << "Phonebook is empty. Add contacts first." << std::endl;
        return "";
    }

	std::cout << "Enter the index of the contact you want to search for: ";
    if(!getline(std::cin, input)) {
		std::cout << "\nError reading input. Ctrl D detected. Exiting..." << std::endl;
		return "";
	}

    try {
        index = ft_atoi(input);
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        displayContact(index);
    } catch (const std::invalid_argument& e) {
		std::cout << "Invalid input. Please enter a number." << std::endl;
    } catch (const std::out_of_range& e) {
		std::cout << "Index out of range. Valid range: 0 to " << size - 1 << "." << std::endl;
    }

    return input;
}

