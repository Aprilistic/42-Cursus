#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }
void Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
  _totalAmount += initial_deposit;
}
Account::~Account() {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
            << std::endl;
}

void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
            << ";deposit:" << deposit << ";amount:" << _amount + deposit
            << ";nb_deposits:" << ++_nbDeposits << std::endl;
  _amount += deposit;
  _totalAmount += deposit;
  _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
            << ";withdrawal:";
  if (withdrawal > _amount) {
    std::cout << "refused" << std::endl;
    return false;
  }
  std::cout << withdrawal << ";amount:" << _amount - withdrawal
            << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;
  return true;
}

int Account::checkAmount() const { return _amount; }

void Account::displayStatus() const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t elapsed_second = time(NULL);
  struct tm *current_time = localtime(&elapsed_second);

  std::cout << "[" << std::setw(4) << std::setfill('0')
            << current_time->tm_year + 1990 << std::setw(2) << std::setfill('0')
            << current_time->tm_mon + 1 << std::setw(2) << std::setfill('0')
            << current_time->tm_mday << "_" << std::setw(2) << std::setfill('0')
            << current_time->tm_hour << std::setw(2) << std::setfill('0')
            << current_time->tm_min << std::setw(2) << std::setfill('0')
            << current_time->tm_sec << "] ";
}
