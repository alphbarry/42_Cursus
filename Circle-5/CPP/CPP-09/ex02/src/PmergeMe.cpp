#include "../inc/PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

void PmergeMe::parseArguments(int argc, char* argv[]) {
	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
		
		if (arg.empty()) {
			std::cerr << "Error" << std::endl;
			exit(1);
		}

		for (size_t j = 0; j < arg.length(); ++j) {
			if (arg[j] < '0' || arg[j] > '9') {
				std::cerr << "Error" << std::endl;
				exit(1);
			}
		}

		std::istringstream iss(arg);
		int num;
		iss >> num;

		if (iss.fail() || !iss.eof() || num < 0) {
			std::cerr << "Error" << std::endl;
			exit(1);
		}

		_originalData.push_back(num);
		_vectorData.push_back(num);
		_dequeData.push_back(num);
	}
}

template<typename Container>
size_t PmergeMe::binarySearch(const Container& container, int value, size_t left, size_t right) const {
	while (left < right) {
		size_t mid = left + (right - left) / 2;
		if (container[mid] < value) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return left;
}

template<typename Container>
void PmergeMe::sortPairs(Container& container) {
	for (size_t i = 0; i < container.size() - 1; i += 2) {
		if (container[i] > container[i + 1]) {
			std::swap(container[i], container[i + 1]);
		}
	}
}

template<typename Container>
void PmergeMe::insertSmallElements(Container& mainChain, Container& pend) {
	if (pend.empty()) {
		return;
	}

	if (pend.size() == 1) {
		int value = pend[0];
		size_t pos = binarySearch(mainChain, value, 0, mainChain.size());
		mainChain.insert(mainChain.begin() + pos, value);
		return;
	}

	int firstValue = pend[0];
	size_t firstPos = binarySearch(mainChain, firstValue, 0, mainChain.size());
	mainChain.insert(mainChain.begin() + firstPos, firstValue);

	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(3);
	
	size_t j = 2;
	while (jacobsthal.back() < pend.size()) {
		size_t next = jacobsthal[j - 1] + 2 * jacobsthal[j - 2];
		jacobsthal.push_back(next);
		++j;
	}

	size_t inserted = 1;
	for (size_t i = 1; i < jacobsthal.size() && inserted < pend.size(); ++i) {
		size_t end = jacobsthal[i];
		if (end > pend.size()) {
			end = pend.size();
		}
		
		for (size_t k = end; k > inserted; --k) {
			if (k - 1 < pend.size()) {
				int value = pend[k - 1];
				size_t pos = binarySearch(mainChain, value, 0, mainChain.size());
				mainChain.insert(mainChain.begin() + pos, value);
			}
		}
		inserted = end;
	}
}

template<typename Container>
void PmergeMe::mergeInsertSort(Container& container) {
	if (container.size() <= 1) {
		return;
	}

	bool hasStraggler = (container.size() % 2 == 1);
	int straggler = 0;
	if (hasStraggler) {
		straggler = container.back();
		container.pop_back();
	}

	sortPairs(container);

	Container mainChain;
	Container pend;

	for (size_t i = 0; i < container.size(); i += 2) {
		mainChain.push_back(container[i + 1]);
		pend.push_back(container[i]);
	}

	if (mainChain.size() > 1) {
		mergeInsertSort(mainChain);
	}

	if (!pend.empty()) {
		insertSmallElements(mainChain, pend);
	}

	if (hasStraggler) {
		size_t pos = binarySearch(mainChain, straggler, 0, mainChain.size());
		mainChain.insert(mainChain.begin() + pos, straggler);
	}

	container = mainChain;
}

void PmergeMe::sort() {
	clock_t start, end;
	double vectorTime, dequeTime;

	std::vector<int> vectorCopy = _vectorData;
	std::deque<int> dequeCopy = _dequeData;

	start = clock();
	mergeInsertSort(vectorCopy);
	end = clock();
	vectorTime = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000;

	start = clock();
	mergeInsertSort(dequeCopy);
	end = clock();
	dequeTime = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000;

	_vectorData = vectorCopy;
	_dequeData = dequeCopy;

	std::cout << "Time to process a range of " << _vectorData.size() 
			  << " elements with std::vector : " << std::fixed << std::setprecision(5) 
			  << vectorTime << " us" << std::endl;
	
	std::cout << "Time to process a range of " << _dequeData.size() 
			  << " elements with std::deque : " << std::fixed << std::setprecision(5) 
			  << dequeTime << " us" << std::endl;
}

void PmergeMe::displayResults() const {
	std::cout << "Before: ";
	for (size_t i = 0; i < _originalData.size(); ++i) {
		std::cout << _originalData[i];
		if (i < _originalData.size() - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < _vectorData.size(); ++i) {
		std::cout << _vectorData[i];
		if (i < _vectorData.size() - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

template void PmergeMe::mergeInsertSort<std::vector<int> >(std::vector<int>&);
template void PmergeMe::mergeInsertSort<std::deque<int> >(std::deque<int>&);
template void PmergeMe::sortPairs<std::vector<int> >(std::vector<int>&);
template void PmergeMe::sortPairs<std::deque<int> >(std::deque<int>&);
template void PmergeMe::insertSmallElements<std::vector<int> >(std::vector<int>&, std::vector<int>&);
template void PmergeMe::insertSmallElements<std::deque<int> >(std::deque<int>&, std::deque<int>&);
template size_t PmergeMe::binarySearch<std::vector<int> >(const std::vector<int>&, int, size_t, size_t) const;
template size_t PmergeMe::binarySearch<std::deque<int> >(const std::deque<int>&, int, size_t, size_t) const;
