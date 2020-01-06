# SMT Generator
Currently the parser only handles the case of simple assignment statements and if-else statements. There is no support of comments. When compiling remove all declarations, function calls, pointer expressions, bit operations, arrays, and comments.
## Executables
  - `a.out` :: Generate SMT code from C program. Will generate two file, `inputfile.smt` and `inputfile.var`. `.var` file contains the list of variables used in the program.
    ```
    usage: ./a.out inputfile
    ```
  - `varequiv.py` :: Generate SMT code for checking variable equivalence.
    ```
    usage: varequiv.py [-h] -s CSMT -r HSMT -v VFILE [-o OUT]
    
    Generate SMT program for checking equivalence of variables.
    
    optional arguments:
      -h, --help            show this help message and exit
      -s CSMT, --cfile CSMT
                            SMT program of the C source.
      -r HSMT, --hlsfile HSMT
                            SMT of the HLS source.
      -v VFILE, --vfile VFILE
                            File containing the list of variables.
      -o OUT, --outfile OUT
                            File where the output will be written
    ```
## Check variable equivalence
  1. Generate the SMT programs for the two input programs.
  2. Create a file with the following format:
     - Line 1 contains input variables of the first program (the one denote by `-s` i.e. CSMT program).
     - Line 2 contains input variables for HSMT program (given by `-r`).
     - Line 3 contains interior variables of first program.
     - Line 4 contains interior variable of second program.
  3. Run the program `varequiv.py` with the proper arguments.
## Satisfiability and SMT model
  Add ~(check-sat)~ and ~(get-model)~ at the end of ~outfile~.
