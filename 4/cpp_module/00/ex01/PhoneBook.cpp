#include "PhoneBook.hpp"
#include <cstdio>
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() {
  std::cout << "Opening Phonebook...\n\n";
  group_size = 0;
  oldest_index = 0;
}

PhoneBook::~PhoneBook() { std::cout << "Closing Phonebook...\n\n"; }

void PhoneBook::showAvailableOption() const {
  std::cout << "1: ADD, 2: SEARCH, 3: EXIT\n\n";
}

void PhoneBook::addContact() {
  if (group_size < 8)
    group_size++;
  for (int i = 0; i < 5; ++i)
    group[oldest_index].setVariables(i);
  oldest_index++;
}

void PhoneBook::showSavedContacts() const {
  std::cout << std::setw(10) << "Index"
            << "|";
  std::cout << std::setw(10) << "Firstname"
            << "|";
  std::cout << std::setw(10) << "Lastname"
            << "|";
  std::cout << std::setw(10) << "Nickname" << std::endl;

  if (group_size == 0)
    std::cout << "Phonebook is empty now.\n";
  for (int i = 0; i < group_size; ++i) {
    int target_index = (oldest_index + i) % group_size;
    std::cout << std::setw(10) << target_index << "|";
    std::cout << std::setw(10) << group[target_index].getFirstName() << "|";
    std::cout << std::setw(10) << group[target_index].getLastName() << "|";
    std::cout << std::setw(10) << group[target_index].getNickName() << std::endl;
  }
  std::cout << std::endl;
}

void PhoneBook::getContactInfo() const {
  int selected_index;
  while (1) {
    std::cout << "Select the index to search: ";
    std::cin >> selected_index;
    if (selected_index < 0 || group_size <= selected_index)
      std::cout << "Wrong index. Try again." << std::endl;
    else
      break;
  }
  std::cout << "<<Your requested information>>" << std::endl;
  std::cout << "First name: " << group[selected_index].getFirstName()
            << std::endl;
  std::cout << "Last name: " << group[selected_index].getLastName()
            << std::endl;
  std::cout << "Nickname: " << group[selected_index].getNickName() << std::endl;
  std::cout << "Phone number: " << group[selected_index].getPhoneNumber()
            << std::endl;
}

void PhoneBook::searchContact() const {
  showSavedContacts();
  getContactInfo();
}

void PhoneBook::runPhoneBookOperation() {
  std::string command;

  while (true) {
    showAvailableOption();
    std::cout << "Enter command: ";
    getchar();
    std::cin >> command;
    if (command == "ADD") {
      addContact();
    } else if (command == "SEARCH") {
      searchContact();
    } else if (command == "EXIT") {
      break;
    } else {
      std::cout << "Invalid command. Enter again.\n";
    }
  }
}