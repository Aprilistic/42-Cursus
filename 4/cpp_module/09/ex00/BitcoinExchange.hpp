#ifndef BITCOINEXCHANGE_HPP_
#define BITCOINEXCHANGE_HPP_

#include <cstddef>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
private:
  static std::map<std::string, double> _db;

  BitcoinExchange();
  BitcoinExchange(BitcoinExchange const &copy);
  ~BitcoinExchange();

  BitcoinExchange &operator=(BitcoinExchange const &copy);

  static bool isValidDate(std::string const &date);
  static bool isValidAmount(std::string const &amount);
  static std::string getResult(std::string line);

public:
  static bool setDB();
  static bool runBTC(std::string const &input);
};

#endif // BITCOINEXCHANGE_HPP_