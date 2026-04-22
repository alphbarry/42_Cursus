/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alphbarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:40:29 by alphbarr          #+#    #+#             */
/*   Updated: 2025/06/09 17:51:34 by alphbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
#define HARL_CPP

#include <iostream>
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define GRAY	 "\033[90m"

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif
