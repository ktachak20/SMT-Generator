# SMT Generator

Generates smt code from c source. Currently supports simple statements,
decisions and arrays.

Since, variable declarations are not supported currently there is no means
of differentiating between input, interior, and output variables. Hence the
task is a 3 step process as given below:
1. generate Z3 smt code usrin the executable generated from `main.c`.
This step will generate Z3 SMT program with no declarations and a `.var`
containing the variable names and types.

2. To check variable equivalence, create a file containing four lines,
the first line is the list of input variables for the first c file, the
second line is the list of input variables for the second c file. The
third line is the list of interior variables for the first c file and the
last/fourth line is the list of interior variables for the second c file
respectively.

3. Run the `varequiv.py` script passing in the appropriate arguments.

## Executables
  - `a.out` :: Generate SMT code from C program. Will generate two file, `inputfile.smt` and `inputfile.var`. `.var` file contains the list of variables used in the program.
    ```
    usage: ./a.out inputfile
    ```

    To generate this executable, compile the `main.c` file linking in the
    dependencies. For example,
    ```make
    cc main.c smtlib.c smtlib.tab.c lex.yy.c -I ./ -D DEBUG
    ```

    Use the debug flag to turn on debugging mode.
    
  - `varequiv.py` :: Generate SMT code for checking variable equivalence.
    ```
    usage: varequiv.py [-h] -s CSMT -r HSMT -v VFILE -o OUT [-t]
    
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
      -t, --timeit          Print the running time.
    ```

## Satisfiability and SMT model
  Add `(check-sat)` and `(get-model)` at the end of `outfile`.
