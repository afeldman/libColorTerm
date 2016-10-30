#pragma once

#include <string>
#include <ostream>

namespace ColorTerm {

  const std::string red("\033[0;31m");
  const std::string green("\033[1;32m");
  const std::string yellow("\033[1;33m");
  const std::string cyan("\033[0;36m");
  const std::string magenta("\033[0;35m");
  const std::string reset("\033[0m");

  class Modifier {
    const std::string m_color;
  public:
    Modifier(const std::string color) : m_code(color) {}
    friend std::ostream&
    operator<<(std::ostream& os, const Modifier& mod) {
      return os << "\033[" << mod.m_color << "m";
    }
  };

}
