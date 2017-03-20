#ifndef __BLINK_UTIL__
#define __BLINK_UTIL__

#include <typeinfo>
#include <cxxabi.h>
#include <memory>
#include <cstddef>
#include <sstream>

#include <vector>


namespace blink {
  class Util {
    public:
      template<typename T>
      static std::unique_ptr<char> getType(T var) {
        int status = 0;
        std::unique_ptr<char> strName(abi::__cxa_demangle(typeid(var).name(), nullptr, 0, &status));
        return strName;
      }

      static void split(const std::string &text, char delim, std::vector<std::string> &tokens) {
        std::stringstream ss;
        ss.str(text);
        std::string elem;
        while (std::getline(ss, elem, delim)) {
            tokens.push_back(elem);
        }
      }

  };
}
#endif
