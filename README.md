# Calculator Project

A versatile and efficient C++ calculator with support for arithmetic operations, variables, and expression evaluation. This project is structured for clarity and scalability, offering modular components for tokenization, parsing, evaluation, and symbol management.

## Features

- **Arithmetic Operations**: Supports `+`, `-`, `*`, `/`, and `^` (exponentiation).  
- **Variables**: Assign and reuse variables (e.g., `let x = 5; let y = x + 3`).  
- **Parentheses**: Group expressions for priority operations (e.g., `(x + 2) * 3`).  

## Project Overview

The project is designed with a clean modular structure to facilitate ease of understanding, testing, and expansion:

```plaintext
calc/
.
├── CMakeLists.txt          # Build configuration
├── LICENSE                 # Project license
├── README.md               # Documentation
├── docs/                   
│   └── grammar.md          # Calculator grammar definition
└── src/
    ├── Calculator.cpp      # Core calculator logic
    ├── Calculator.h        # Header for Calculator class
    ├── Constants.h         # Project constants and settings
    ├── Token.h             # Token definitions
    ├── TokenStream.cpp     # Tokenization implementation
    ├── TokenStream.h       # Header for TokenStream class
    ├── Variables.cpp       # Variable management implementation
    ├── Variables.h         # Header for Variables class
    └── main.cpp            # Application entry point
```

## Getting Started

### Prerequisites

- A **C++20** compliant compiler (e.g., GCC, Clang, MSVC).
- **CMake 3.15** or newer for build automation.

### Build and Run Instructions

1. **Clone the repository**:

   ```bash
   git clone https://github.com/mrezabayat/calc.git
   cd calc
   ```

2. **Build the project**:

   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
   ```

3. **Run the calculator**:

   ```bash
   ./calc
   ```

## Usage Example

```plaintext
> x = 5
> y = x + 3
> z = (y - 2) * 4
> z
24
```

Explore complex expressions, assign variables, and evaluate with ease!

## Grammar Definition

The calculator's grammar syntax is defined in [docs/grammar.md](docs/grammar.md). It outlines the rules for writing valid expressions, assignments, and operations.

## Contributing

Contributions are welcome and encouraged!  
To contribute:

1. Fork the repository.  
2. Create a feature branch.  
3. Submit a pull request with detailed notes on your changes.  

## License

This project is released under the [MIT License](LICENSE), permitting use, modification, and distribution under the terms of the license.

Developed with a focus on simplicity, readability, and extensibility. Whether you're a beginner or an expert, this calculator is a great way to explore or showcase modular C++ development.
