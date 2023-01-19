#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

void Contact::setNonEmptyString(std::string &str) {
  while (true) {
    std::getline(std::cin, str);
    if (std::cin.eof()) {
      std::cout << "Invalid command. Enter again.\n :";
      std::cin.clear();
      clearerr(stdin);
      continue;
    }
    str.erase(0, str.find_first_not_of("\t\n "));
    str.erase(str.find_last_not_of("\t\n ") + 1);
    if (str.length() > 0)
      break;
    std::cout << "Empty input is forbidden. Try again." << std::endl;
    std::cout << ": ";
  }
}

std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
std::string Contact::getNickName() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phone_number; }

void Contact::setVariables(int mode) {
  switch (mode) {
  case 0:
    std::cout << "Enter first name: ";
    setNonEmptyString(first_name);
    break;
  case 1:
    std::cout << "Enter last name: ";
    setNonEmptyString(last_name);
    break;
  case 2:
    std::cout << "Enter nickname: ";
    setNonEmptyString(nickname);
    break;
  case 3:
    std::cout << "Enter phone number: ";
    setNonEmptyString(phone_number);
    break;
  case 4:
    std::cout << "Enter secret: ";
    setNonEmptyString(darkest_secret);
    break;
  }
}

Contact::Contact() {}
Contact::~Contact() {}
