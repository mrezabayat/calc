# Calculator grammar

```plaintext
<program>       ::= <statement> | <statement> <program>

<statement>     ::= <assignment> | <expression>

<assignment>    ::= <identifier> '=' <expression>

<expression>    ::= <term> | <expression> '+' <term> | <expression> '-' <term>

<term>          ::= <factor> | <term> '*' <factor> | <term> '/' <factor>

<factor>        ::= <number> | <identifier> | '(' <expression> ')'

<identifier>    ::= [a-zA-Z_] [a-zA-Z0-9_]*

<number>        ::= [0-9]+ ('.' [0-9]+)?
```
