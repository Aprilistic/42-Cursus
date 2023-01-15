#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string phone_number;
  std::string darkest_secret;

  void setNonEmptyString(std::string &str);

public:
  void setVariables(int mode);

  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getNickName() const;
  std::string getPhoneNumber() const;

  Contact();
  ~Contact();
};

#endif