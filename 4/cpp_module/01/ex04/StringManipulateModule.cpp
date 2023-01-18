#include "StringManipulateModule.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void StringManipulateModule::ReplaceString(std::string *text,
                                           const std::string &s1,
                                           const std::string &s2) {
  std::size_t found;
  while (true) {
    found = text->find(s1);
    if (found == std::string::npos)
      break;
    (*text).erase(found, s1.length());
    (*text).insert(found, s2);
  }
}

void StringManipulateModule::SaveSubstitutedString(const std::string &filename,
                                                   const std::string &s1,
                                                   const std::string &s2) {

  if (filename.empty() || s1.empty() || s2.empty()) {
    std::cerr << "Empty argument(s) has(have) been found" << std::endl;
    return;
  }

  std::ifstream original_file;

  original_file.open(filename, std::ifstream::in);
  if (!original_file.good()) {
    std::cerr << "Cannot open file \'" << filename << "\'" << std::endl;
    return;
  }

  std::ostringstream ss;
  ss << original_file.rdbuf();
  original_file.close();
  std::string temp = ss.str();
  ReplaceString(&temp, s1, s2);

  std::ofstream new_file;
  new_file.open(filename + ".replace",
                std::ofstream::out | std::ofstream::trunc);
  if (!new_file.good()) {
    std::cerr << "Cannot open file \'" << filename + ".replace"
              << "\'" << std::endl;
    return;
  }
  new_file << temp;
  new_file.close();
}
