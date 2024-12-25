# Calculator grammar

```plaintext
Calculation:
    Statement
    Print
    Quit
    Calculation Statement

Statement:
    Declaration
    Expression

Declaration:
    "let" name "=" Expression

Print:
    ";"

Quit:
    "q"

Expression:
    Term
    Expression "+" Term
    Expression "-" Term

Term:
    Primary
    Term "*" Primary
    Term "/" Primary
    Term "%" Primary

Primary:
    Number
    "(" Expression ")"
    "-" Primary
    "+" Primary
    Primary "^" Primary

Number:
    floating-point-literal
```
