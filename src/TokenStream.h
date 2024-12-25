// Copyright (c) 2024 Mohammad Reza Bayat. All rights reserved.

#pragma once

#include "Token.h"

namespace calc {
class TokenStream {
public:
  Token get();
  void putback(Token t); // putback a token to the stream
  void ignore(char c);   // discard characters upto and including 'c'
private:
  bool m_full{false};
  Token m_buffer{'0'};
};
} // namespace calc
