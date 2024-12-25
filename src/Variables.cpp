// Copyright (c) 2024 Mohammad Reza Bayat. All rights reserved.

#include "Variables.h"

namespace calc {

double Variables::get_value(const std::string &var) {
  if (m_variableTable.find(var) != m_variableTable.end()) {
    return m_variableTable[var];
  }
  throw std::runtime_error("Trying to read undefined variable: " + var);
}

bool Variables::is_declared(const std::string &name) {
  return m_variableTable.find(name) != m_variableTable.end() ? true : false;
}

void Variables::define_var(const std::string &name, double value) {
  if (is_declared(name)) {
    throw std::runtime_error(name + " declared twice.\n");
  }
  m_variableTable[name] = value;
}

void Variables::set_value(const std::string &name, const double value) {
    if (!is_declared(name)) {
      throw std::runtime_error(name + " is not declared.\n");
    }
    m_variableTable[name] = value;
  }

} // namespace calc
