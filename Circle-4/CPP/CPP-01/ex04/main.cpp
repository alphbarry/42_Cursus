/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:40:59 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 16:41:01 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	main(int ac, char **av) {
	std::string	s1;
	std::string	s2;
	std::string	filename_r;
	std::ifstream	filename;
	std::ofstream	filename_replace;
	std::string	line;

	if (ac != 4) {
		std::cout << "Usage: " << av[0] << " <string1> <string2>" << std::endl;
		return 1;
	}
	filename.open(av[1]);
	s1 = av[2];
	s2 = av[3];
	filename_r = std::string(av[1]) + ".replace";
	filename_replace.open(filename_r.c_str());
	if (!filename.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return 1;
	}
	else {
		if (!filename_replace.is_open()){
			std::cerr << "Error opening file for writing!" << std::endl;
			return 1;
		}
		while (getline(filename, line)) {
			size_t pos = 0;
			while ((pos = line.find(s1, pos)) != std::string::npos) {
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos += s2.length();
			}
			filename_replace << line << std::endl;
		}
		filename.close();
		filename_replace.close();
	}

	return 0;
}
