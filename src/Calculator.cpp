// Copyright (c) 2024 Mohammad Reza Bayat. All rights reserved.

#include "Calculator.h"
#include "Constants.h"
#include <iostream>

namespace calc {

void Calculator::run() {
  while (std::cin) {
    try {
      std::cout << ConstToken::prompt;
      Token token = m_tokenStream.get();
      if (token.kind == ConstToken::quit) {
        break;
      }
      if (token.kind == ConstToken::print) {
        continue;
      }

      m_tokenStream.putback(token);
      std::cout << ConstToken::result << statement() << '\n';

    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      m_tokenStream.ignore(ConstToken::print);
    }
  }
}

double Calculator::statement() {
  Token token = m_tokenStream.get();
  switch (token.kind) {
  case ConstToken::let:
    return declaration();
  default:
    m_tokenStream.putback(token);
    return expression();
  }
}

double Calculator::declaration() {
  Token nameToken = m_tokenStream.get();
  if (nameToken.kind != ConstToken::name)
    throw std::runtime_error("Variable name expected in the declaration.\n");

  Token equality_token = m_tokenStream.get();
  if (equality_token.kind != '=')
    throw std::runtime_error("= missing in declaration of" +
                             equality_token.name);

  double value = expression();
  m_variables.define_var(nameToken.name, value);
  return value;
}

double Calculator::expression() {
  double left = term();
  Token token = m_tokenStream.get();
  while (true) {
    switch (token.kind) {
    case '+':
      left += term();
      token = m_tokenStream.get();
      break;
    case '-':
      left -= term();
      token = m_tokenStream.get();
      break;
    default:
      m_tokenStream.putback(token);
      return left;
    }
  }
}

double Calculator::term() {
  double left = primary();
  Token t = m_tokenStream.get();
  while (true) {
    switch (t.kind) {
    case '*':
      left *= primary();
      t = m_tokenStream.get();
      break;

    case '/': {
      double denum = primary();
      if (denum == 0)
        throw std::runtime_error("Division by zero.\n");
      left /= denum;
      t = m_tokenStream.get();
      break;
    }

    case '%': {
      double denum = primary();
      if (denum == 0)
        throw std::runtime_error("%: dnum is zero\n");
      left = std::fmod(left, denum);
      t = m_tokenStream.get();
      break;
    }

    default:
      m_tokenStream.putback(t);
      return left;
    }
  }
}

double Calculator::primary() {
  Token left = m_tokenStream.get();

  switch (left.kind) {
  case '(': {
    double exp = expression();
    left = m_tokenStream.get();
    if (left.kind != ')')
      throw std::runtime_error("Expected ).\n");
    return exp;
  }
  case ConstToken::number:
    break;
  case '-':
    return -primary(); // Handle unary minus
  case '+':
    return primary(); // Handle unary plus
  default:
    throw std::runtime_error("Primary expected.\n");
  }

  Token right = m_tokenStream.get();

  if (right.kind == '^') {
    double right = primary();
    return std::pow(left.value, right);
  }

  m_tokenStream.putback(right);

  return left.value;
}

} // namespace calc
