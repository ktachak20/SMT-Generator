# SMT Generator
Currently the parser only handles the case of simple assignment statements and if-else statements. There is no support of comments. When compiling remove all declarations, function calls, pointer expressions, bit operations, arrays, and comments.
## Files
  - `smtlib.y` :: Parser containing the grammar specification.
  - `smtlib.lex` :: Lexical analyzer containing specification for tokens.
  - `a.out` :: Program for converting input file to SMT code.
## Usage
  ~./a.out inputfile outfile~
## Satisfiability and SMT model
  Add ~(check-sat)~ and ~(get-model)~ at the end of ~outfile~.
