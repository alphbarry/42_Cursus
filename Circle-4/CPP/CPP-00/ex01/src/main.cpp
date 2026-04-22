/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:53:51 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 16:54:15 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"
using namespace std;

bool	isEmptyOrWhitespace(string& str) {
	return str.find_first_not_of(" \t\n\v\f\r") == string::npos;
}

int main() {
    Phonebook phonebook;
	string	contact[5];
    string input;
    int i = 0;

    while (true) {
        cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!getline(cin, input)) {
			cout << "\nError reading input. Ctrl D detected. Exiting..." << endl;
			break;
		}
        if (input == "ADD") {
            cout << "Enter contact information:" << endl;
			for (int j = 0; j < 5; j++) {
				string prompts[5] = {
					"- First name: ",
					"- Last name: ",
					"- Nickname: ",
					"- Phone number: ",
					"- Darkest secret: "
				};
				do {
					cout << prompts[j];
					if(!getline(cin, contact[j])) {
						cout << "\nError reading input. Ctrl D detected. Exiting..." << endl;
						return 1;
					}
					if (isEmptyOrWhitespace(contact[j]))
						cout << "Field cannot be empty. Please enter again." << endl;
				} while (isEmptyOrWhitespace(contact[j]));
			}
			phonebook.addContact(contact);
            i++;
            cout << "Contact added! You can ADD more, SEARCH, or EXIT." << endl;
        }
        else if (input == "SEARCH") {
            phonebook.searchContacts();
        }
        else if (input == "EXIT") {
            cout << "Exiting phonebook. Goodbye!" << endl;
            break;
        }
        else {
    		cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Unknown command. Please use 'ADD', 'SEARCH', or 'EXIT'." << endl;
        }
    }
    return 0;
}
