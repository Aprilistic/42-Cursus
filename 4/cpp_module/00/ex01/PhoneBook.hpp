#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
  Contact group[8];
  int group_size;
  int oldest_index;

  void showAvailableOption() const;
  void showSavedContacts() const;
  void getContactInfo() const;

public:
  void addContact();
  void searchContact() const;

  void runPhoneBookOperation();

  PhoneBook();
  ~PhoneBook();
};

#endif