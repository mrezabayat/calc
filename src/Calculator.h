// Copyright (c) 2024 Mohammad Reza Bayat. All rights reserved.

#pragma once

#include "TokenStream.h"
#include "Variables.h"
#include <string>
#include <unordered_map>

namespace calc {

class Calculator {
public:
  Calculator() = default;
  void run();

private:
  TokenStream m_tokenStream;
  Variables m_variables;

  double statement();
  double declaration();
  double expression();
  double term();
  double primary();
};

} // namespace calc
