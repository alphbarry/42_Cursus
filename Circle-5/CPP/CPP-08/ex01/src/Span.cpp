#include "../inc/Span.hpp"

Span::Span(void) : _n(100) {}
Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &src){
	*this = src;
}

Span::~Span(void) {}

Span &Span::operator=(const Span &rhs) {
	if (this != &rhs) {
		_n = rhs._n;
		_numbers = rhs._numbers;
	}
	return *this;
}

void Span::addNumber(int n) {
	if (_numbers.size() >= _n) {
		throw SpanFullException();
	}
	if (std::find(_numbers.begin(), _numbers.end(), n) != _numbers.end()) {
		throw AlreadyExistsException();
	}
	_numbers.push_back(n);
}

int Span::shortestSpan(void) const {
	if (_numbers.size() < 2) {
		throw NotEnoughNumbersException();
	}
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i) {
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

int Span::longestSpan(void) const {
	if (_numbers.size() < 2) {
		throw NotEnoughNumbersException();
	}
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	return max - min;
}
