// Copyright (c) 2024 Mohammad Reza Bayat. All rights reserved.

#pragma once

#include <string>
#include <unordered_map>

namespace calc {
class Variables {
public:
  double get_value(const std::string &var);
  bool is_declared(const std::string &name);
  void define_var(const std::string &name, double value);
  void set_value(const std::string &name, const double value);

private:
  std::unordered_map<std::string, double> m_variableTable;
};
} // namespace calc