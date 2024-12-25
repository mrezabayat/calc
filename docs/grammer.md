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
    Factor
    Term "*" Factor
    Term "/" Factor
    Term "%" Factor

Factor:
    Primary
    Factor "^" Primary

Primary:
    Number
    "(" Expression ")"
    "-" Primary
    "+" Primary

Number:
    floating-point-literal
```
