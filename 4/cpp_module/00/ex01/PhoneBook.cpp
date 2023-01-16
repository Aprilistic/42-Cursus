#include "PhoneBook.hpp"
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>

PhoneBook::PhoneBook() {
  std::cout << "Opening Phonebook...\n\n";
  group_size = 0;
  oldest_index = 0;
}

PhoneBook::~PhoneBook() { std::cout << "Closing Phonebook...\n\n"; }

void PhoneBook::showAvailableOption() const {
  std::cout << "1: ADD, 2: SEARCH, 3: EXIT\n";
}

std::string PhoneBook::getCompressedString(std::string str) const {
  if (str.length() > 10) {
    str[9] = '.';
    str.erase(10);
  }
  return str;
}

void PhoneBook::showSavedContacts() const {
  std::cout << std::setw(10) << "Index"
            << "|";
  std::cout << std::setw(10) << "Firstname"
            << "|";
  std::cout << std::setw(10) << "Lastname"
            << "|";
  std::cout << std::setw(10) << "Nickname" << std::endl;

  for (int i = 0; i < group_size; ++i) {
    int target_index = (oldest_index + i) % group_size;

    std::cout << std::setw(10) << i << "|";
    std::cout << std::setw(10)
              << getCompressedString(group[target_index].getFirstName()) << "|";
    std::cout << std::setw(10)
              << getCompressedString(group[target_index].getLastName()) << "|";
    std::cout << std::setw(10)
              << getCompressedString(group[target_index].getNickName())
              << std::endl;
  }
  std::cout << std::endl;
}

void PhoneBook::getContactInfo() const {
  int selected_index;
  while (1) {
    std::cout << "Select the index to search: ";
    std::cin >> selected_index;
    if (std::cin.fail()) {
      std::cout << "Wrong datatype. Type integer." << std::endl;
      std::cin.clear();
      std::cin.ignore();
    } else if (selected_index < 0 || group_size <= selected_index)
      std::cout << "Wrong index. Try again." << std::endl;
    else
      break;
  }
  selected_index = (selected_index + oldest_index) % group_size;
  std::cout << "\n<<Your requested information>>\n";
  std::cout << "First name: " << group[selected_index].getFirstName()
            << std::endl;
  std::cout << "Last name: " << group[selected_index].getLastName()
            << std::endl;
  std::cout << "Nickname: " << group[selected_index].getNickName() << std::endl;
  std::cout << "Phone number: " << group[selected_index].getPhoneNumber()
            << std::endl
            << std::endl;
}

void PhoneBook::addContact() {
  if (group_size < 8)
    group_size++;
  for (int i = 0; i < 5; ++i)
    group[oldest_index].setVariables(i);
  oldest_index++;
  oldest_index %= 8;
}

void PhoneBook::searchContact() const {
  if (group_size == 0) {
    std::cout << "Phonebook is empty now.\n\n";
    return;
  }
  showSavedContacts();
  getContactInfo();
}

void PhoneBook::runPhoneBookOperation() {
  std::string command;

  while (true) {
    showAvailableOption();
    std::cout << "Enter command: ";
    std::cin >> command;
    std::cin.ignore();
    if (std::cin.eof()) {
      std::cout << "Invalid command. Enter again.\n";
      std::cin.clear();
      clearerr(stdin);
    } else if (command == "ADD" || command == "1") {
      std::cout << "Save a new contact\n";
      addContact();
    } else if (command == "SEARCH" || command == "2") {
      std::cout << "Display a specific contact\n";
      searchContact();
    } else if (command == "EXIT" || command == "3") {
      break;
    } else {
      std::cout << "Invalid command. Enter again.\n";
    }
  }
}
