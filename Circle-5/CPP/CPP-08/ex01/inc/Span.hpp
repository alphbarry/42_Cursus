#pragma once 

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
	private:
		unsigned int _n;
		std::vector<int> _numbers;
	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span &src);
		~Span(void);

		Span &operator=(const Span &rhs);

		void addNumber(int n);
		int shortestSpan(void) const;
		int longestSpan(void) const;

		class AlreadyExistsException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Number already exists in the span.";
				}
		};

		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Not enough numbers to calculate span.";
				}
		};
		class SpanFullException : public std::exception {
			public:
			virtual const char* what() const throw() {
				return "Span is already full.";
			}
		};
		class SpanEmptyException : public std::exception {
			public:
			virtual const char* what() const throw() {
				return "Span is empty.";
			}
		};
		class SpanTooLargeException : public std::exception {
			public:
			virtual const char* what() const throw() {
				return "Span is too large.";
			}
		};
};

template <typename T>
void print(const T &container) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
