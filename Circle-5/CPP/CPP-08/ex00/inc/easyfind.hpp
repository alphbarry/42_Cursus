#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw std::runtime_error("Value not found in the container");
	}
	return it;
}

template <typename T>
void	print(const T &container) {
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
