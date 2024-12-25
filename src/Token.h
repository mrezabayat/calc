// Copyright (c) 2024 Mohammad Reza Bayat. All rights reserved.

#pragma once

#include <string>

namespace calc {

class Token {
public:
  char kind;    // what kind of token
  double value; // for numbers: a value
  std::string name;
  
  Token(char ch, double val = 0) : kind(ch), value(val) {}
  Token(char ch, std::string var_name, double val = 0)
      : kind(ch), value(val), name(std::move(var_name)) {}
};

} // namespace calc