#include "BitcoinExchange.hpp"

std::map<std::string, double> BitcoinExchange::_db;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) { (void)copy; }

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy) {
  (void)copy;
  return *this;
}

bool BitcoinExchange::isValidDate(std::string const &date) {
  struct tm tm;
  if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL) {
    return false;
  }
  return true;
}

bool BitcoinExchange::isValidAmount(std::string const &amount) {
  std::stringstream ss(amount);
  double d;
  ss >> d;
  if (ss.fail() || !ss.eof()) {
    return false;
  }
  return true;
}

std::string BitcoinExchange::getResult(std::string line) {
  std::stringstream ss(line);

  std::string date_str, amount_str;
  double amount;

  if (std::getline(ss, date_str, '|') && std::getline(ss, amount_str)) {
    if (!isValidDate(date_str)) {
      return "Error: bad input => " + date_str;
    } else if (!isValidAmount(amount_str)) {
      return "Error: bad input => " + amount_str;
    }

    if (isspace(date_str[date_str.size() - 1]))
      date_str = date_str.substr(0, date_str.size() - 1);

    amount = std::strtod(amount_str.c_str(), nullptr);
    if (amount < 0) {
      return "Error: not a positive number.";
    } else if (amount > 1000) {
      return "Error: too large a number.";
    }

    std::map<std::string, double>::iterator it = _db.lower_bound(date_str);
    if (it == _db.begin()) {
      return "Error: no data available for this date.";
    }
    --it;

    double exchange_rate = it->second;
    double result = amount * exchange_rate;
    std::stringstream result_ss;
    result_ss << date_str << " => " << amount << " = " << result;
    return result_ss.str();
  } else {
    return "Error: bad input => " + line;
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