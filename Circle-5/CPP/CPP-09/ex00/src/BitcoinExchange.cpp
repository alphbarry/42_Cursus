#include "../inc/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
	parseDatabase(filename);
}

void BitcoinExchange::processFile(const std::string& filename) {
	processInputFile(filename);
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10) {
		return false;
	}
	
	if (date[4] != '-' || date[7] != '-') {
		return false;
	}

	for (size_t i = 0; i < date.length(); ++i) {
		if (i == 4 || i == 7) {
			continue;
		}
		if (date[i] < '0' || date[i] > '9') {
			return false;
		}
	}

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		return false;
	}

	if (month == 2) {
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (isLeap && day > 29) {
			return false;
		}
		if (!isLeap && day > 28) {
			return false;
		}
	}

	return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const {
	if (valueStr.empty()) {
		return false;
	}

	std::istringstream iss(valueStr);
	iss >> value;

	if (iss.fail() || !iss.eof()) {
		return false;
	}

	if (value < 0) {
		return false;
	}

	if (value > 1000) {
		return false;
	}

	return true;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
	
	if (it == _database.end()) {
		if (_database.empty()) {
			return "";
		}
		--it;
		return it->first;
	}

	if (it->first == date) {
		return it->first;
	}

	if (it == _database.begin()) {
		return "";
	}

	--it;
	return it->first;
}

void BitcoinExchange::parseDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;
	while (std::getline(file, line)) {
		if (firstLine) {
			firstLine = false;
			continue;
		}

		if (line.empty()) {
			continue;
		}

		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos) {
			continue;
		}

		std::string date = line.substr(0, commaPos);
		std::string priceStr = line.substr(commaPos + 1);

		if (!isValidDate(date)) {
			continue;
		}

		std::istringstream iss(priceStr);
		double price;
		iss >> price;

		if (iss.fail()) {
			continue;
		}

		_database[date] = price;
	}

	file.close();
}

void BitcoinExchange::processInputFile(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;
	while (std::getline(file, line)) {
		if (firstLine) {
			firstLine = false;
			continue;
		}

		if (line.empty()) {
			continue;
		}

		size_t pipePos = line.find(" | ");
		if (pipePos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pipePos);
		std::string valueStr = line.substr(pipePos + 3);
		
		while (!date.empty() && date[date.length() - 1] == ' ') {
			date.erase(date.length() - 1, 1);
		}
		while (!date.empty() && date[0] == ' ') {
			date.erase(0, 1);
		}

		if (!isValidDate(date)) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string trimmedValue = valueStr;
		while (!trimmedValue.empty() && trimmedValue[0] == ' ') {
			trimmedValue.erase(0, 1);
		}
		while (!trimmedValue.empty() && trimmedValue[trimmedValue.length() - 1] == ' ') {
			trimmedValue.erase(trimmedValue.length() - 1, 1);
		}

		if (trimmedValue.empty()) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (trimmedValue[0] == '-') {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		std::istringstream valueIss(trimmedValue);
		double value;
		valueIss >> value;

		if (valueIss.fail() || !valueIss.eof()) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		std::string closestDate = findClosestDate(date);
		if (closestDate.empty()) {
			std::cout << "Error: no data available for date " << date << std::endl;
			continue;
		}

		double exchangeRate = _database.find(closestDate)->second;
		double result = value * exchangeRate;

		std::cout << date << " => " << value << " = " << result << std::endl;
	}

	file.close();
}

