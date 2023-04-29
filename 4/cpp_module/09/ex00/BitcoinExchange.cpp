#include "BitcoinExchange.hpp"
#include <cstddef>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) { (void)copy; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy) {
  (void)copy;
  return *this;
}

bool BitcoinExchange::isValidDate(std::string const &date) {
  if (date.size() != 10) {
    return false;
  }
  if (date[4] != '-' || date[7] != '-') {
    return false;
  }
  std::string year = date.substr(0, 4);
  std::string month = date.substr(5, 2);
  std::string day = date.substr(8, 2);

  if (year.size() != 4 || month.size() != 2 || day.size() != 2) {
    return false;
  }

  for (std::size_t i = 0; i < year.size(); ++i) {
    if (year[i] < '0' || year[i] > '9') {
      return false;
    }
  }

  for (std::size_t i = 0; i < month.size(); ++i) {
    if (month[i] < '0' || month[i] > '9') {
      return false;
    }
  }

  for (std::size_t i = 0; i < day.size(); ++i) {
    if (day[i] < '0' || day[i] > '9') {
      return false;
    }
  }

  return true;
}

std::string BitcoinExchange::getResult(std::string line) {
  std::stringstream ss(line);
  std::stringstream ret;

  std::string date_str, amount_str;
  double amount;

  if (std::getline(ss, date_str, '|')) {
    if (std::getline(ss, amount_str)) {
    }
  }
}

bool BitcoinExchange::setDB() {
  std::ifstream db("data.csv");
  if (!db.is_open()) {
    return false;
  }

  std::string line;

  std::getline(db, line);

  while (std::getline(db, line)) {
    std::stringstream ss(line);

    std::string date, exchange_rate_str;
    std::getline(ss, date, ',');
    std::getline(ss, exchange_rate_str, ',');

    double exchange_rate = std::strtod(exchange_rate_str.c_str(), nullptr);

    _db[date] = exchange_rate;
  }
  db.close();
  return true;
}

bool BitcoinExchange::runBTC(std::string const &input) {
  std::ifstream in(input);
  if (!in.is_open()) {
    return false;
  }

  std::string line;
  std::getline(in, line);

  while (std::getline(in, line)) {
    std::string result = getResult(line);
    std::cout << result << std::endl;
  }
  in.close();
  return true;
}