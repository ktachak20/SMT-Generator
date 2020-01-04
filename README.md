# SMT Generator
Currently the parser only handles the case of simple assignment statements and if-else statements. There is no support of comments. When compiling remove all declarations, function calls, pointer expressions, bit operations, arrays, and comments.
## Files
  - `smtlib.y` :: Parser containing the grammar specification.
  - `smtlib.lex` :: Lexical analyzer containing specification for tokens.
  - `a.out` :: Program for converting input file to SMT code.
## Usage
First run ~./a.out inputfile~, on the input programs, this will generate ~inputfile.var~ (containing variable list) and ~inputfile.smt~ (smt program).
Then after checking the variables, having two lines with the format ~smt-prog-name: interior variable list~.
Run the ~vareqv~ on the file.
## Satisfiability and SMT model
  Add ~(check-sat)~ and ~(get-model)~ at the end of ~outfile~.
