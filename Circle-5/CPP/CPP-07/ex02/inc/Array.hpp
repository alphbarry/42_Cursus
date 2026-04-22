#pragma once 
#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array {
	private:
		T* _array;
		size_t _size;
	public:
		Array();
		~Array();
		Array(const Array& other);
		Array& operator=(const Array& other);
		Array(size_t size);

		T& operator[](size_t index);
		const T& operator[](size_t index) const;
		size_t size() const;

		class OutOfBoundsException : public std::exception {
			public:
				const char* what() const throw();
		};
};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::~Array() {
	delete[] _array;
}

template <typename T>
Array<T>::Array(size_t size) : _array(new T[size]), _size(size) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(new T[other._size]), _size(other._size) {
	for (size_t i = 0; i < _size; ++i)
		_array[i] = other._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] _array;
		_size = other._size;
		_array = new T[_size];
		for (size_t i = 0; i < _size; ++i)
			_array[i] = other._array[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
size_t Array<T>::size() const {
	return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return "Index out of bounds";
}

