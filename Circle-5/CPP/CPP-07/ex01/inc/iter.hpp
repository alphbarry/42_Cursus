#pragma once

#include <iostream>

template <typename T, typename F>
void iter(T* array, size_t length, F func) {
	if (!array || length == 0) {
		std::cerr << "Error: Invalid array or length." << std::endl;
		return;
	}
	
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}
