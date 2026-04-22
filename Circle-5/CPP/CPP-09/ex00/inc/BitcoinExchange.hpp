#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, double> _database;

	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	bool isValidDate(const std::string& date) const;
	bool isValidValue(const std::string& valueStr, double& value) const;
	std::string findClosestDate(const std::string& date) const;
	void parseDatabase(const std::string& filename);
	void processInputFile(const std::string& filename);

public:
	BitcoinExchange();
	~BitcoinExchange();

	void loadDatabase(const std::string& filename);
	void processFile(const std::string& filename);
};

#endif

