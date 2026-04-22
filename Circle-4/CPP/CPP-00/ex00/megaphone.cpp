/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:43:19 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 16:43:49 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Megaphone{
	public:
		void	makeSound(){
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;		}
};

char	ft_toupper(char c){
	return ((c >= 'a' && c <= 'z') ? c - 32 : c);
}

int	main(int ac, char **av){
	Megaphone	mega;

	if (ac == 1)
		mega.makeSound();
	else{
		for (int i = 0; i < ac; i++){
			for (int j = 0; av[i][j]; j++){
				av[i][j] = ft_toupper(av[i][j]);
			}
		}
		std::cout << av[1] << std::endl;
	}
	return 0;
}
