#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
private:
	std::vector<int> _originalData;
	std::vector<int> _vectorData;
	std::deque<int> _dequeData;

	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

	template<typename Container>
	void mergeInsertSort(Container& container);

	template<typename Container>
	void sortPairs(Container& container);

	template<typename Container>
	void insertSmallElements(Container& mainChain, Container& pend);

	template<typename Container>
	size_t binarySearch(const Container& container, int value, size_t left, size_t right) const;

public:
	PmergeMe();
	~PmergeMe();

	void parseArguments(int argc, char* argv[]);
	void sort();
	void displayResults() const;
};

#endif

