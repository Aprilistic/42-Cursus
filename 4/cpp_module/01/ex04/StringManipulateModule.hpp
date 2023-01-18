#ifndef STRING_MANIPULATE_MODULE_HPP
#define STRING_MANIPULATE_MODULE_HPP

#include <string>

class StringManipulateModule {
private:
  static void ReplaceString(std::string *text, const std::string &s1,
                            const std::string &s2);

public:
  static void SaveSubstitutedString(const std::string &filename, const std::string &s1,
                                    const std::string &s2);
};

#endif
