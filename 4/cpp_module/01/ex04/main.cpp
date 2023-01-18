#include "StringManipulateModule.hpp"

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "Invalid arguments count. Exit process." << std::endl;
    return 1;
  }

  StringManipulateModule::SaveSubstitutedString(argv[1], argv[2], argv[3]);

  StringManipulateModule::SaveSubstitutedString("a.txt.replace", "Tom", "John");
  
}

//echo "Amy Yma Tommy " > a.txt
