// Copyright (c) 2024 Mohammad Reza Bayat. All rights reserved.

#include "TokenStream.h"
#include "Constants.h"
#include "Token.h"
#include <iostream>

namespace calc {

Token TokenStream::get() {
  if (m_full) {
    m_full = false;
    return m_buffer;
  }

  char ch;
  std::cin >> ch;
  switch (ch) {
  case ';': // for print
  case 'q': // for quit
  case '=':
  case '(':
  case ')':
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
  case '^':
    return Token(ch);
  case '.':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9': {
    std::cin.putback(ch);
    double number{};
    std::cin >> number;
    return Token('n', number);
  }
  default:
    if (std::isalpha(ch)) {
      std::string variable{ch};
      while (std::cin.get(ch) && (std::isalpha(ch) || std::isdigit(ch)))
        variable += ch;
      std::cin.putback(ch);
      if (variable == ConstToken::delkey)
        return Token{ConstToken::let};
      return Token{ConstToken::name, variable};
    }
    throw std::runtime_error("Bad token.\n");
  }
}

void TokenStream::putback(Token t) {
  if (m_full)
    throw std::runtime_error("Putback into a full buffer.\n");
  m_full = true;
  m_buffer = t;
}

void TokenStream::ignore(char c) {
  if (m_full && c == m_buffer.kind) {
    m_full = false;
    return;
  }
  
  m_full = false;
  char ch{};
  while (std::cin >> ch)
    if (ch == c)
      return;
}

} // namespace calc