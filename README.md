# Calculator Project

This project implements a simple calculator in C++ that supports variables and arithmetic operations. The calculator is capable of handling basic expressions, assignments, and variable evaluation. It is built with modular components for tokenization, parsing, evaluation, and symbol management.

## Features

- Arithmetic operations: `+`, `-`, `*`, `/`
- Support for variables (e.g., `x = 5; y = x + 3`)
- Parentheses for grouping expressions (e.g., `(x + 2) * 3`)
- Modular design with lexer, parser, and evaluator components

## Project Structure

```plaintext
calc/
├── src/
│   ├── main.cpp           # Entry point of the application
│   ├── lexer.cpp/.h       # Tokenizer for input strings
│   ├── parser.cpp/.h      # Parser for expressions and statements
│   ├── evaluator.cpp/.h   # Evaluates parsed expressions
│   ├── symbol_table.cpp/.h # Stores and retrieves variables
├── tests/                 # Unit tests for components
├── CMakeLists.txt         # Build configuration
├── README.md              # Project documentation
└── docs/
    └── grammar.md         # Formal grammar for the calculator
```

## Build and Run

### Prerequisites

- C++17 or later
- CMake 3.15 or later
- A C++ compiler (e.g., GCC, Clang, MSVC)

### Steps

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/calculator.git
   cd calculator
   ```

2. Build the project:

   ```bash
   mkdir build && cd build
   conan install .. --output-folder=build --build=missing
   cmake -DCMAKE_BUILD_TYPE=Release ..
   make
   ```

3. Run the program:

   ```bash
   ./calc
   ```

## Grammar

The grammar for the calculator is stored in [docs/grammar.md](docs/grammar.md). This document defines the syntax rules for valid expressions, assignments, and operations.

## Example Usage

```plaintext
> x = 5
> y = x + 3
> z = (y - 2) * 4
> z
24
```

## Testing

Unit tests are located in the `tests/` directory. Run the tests with:

```bash
cd build
ctest
```

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

