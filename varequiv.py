#!/usr/bin/env python


from __future__ import print_function

import sys
import argparse
import timeit


DEC_CONST = '(declare-const {} {})\n'
ASSERT    = '(assert {})\n'
MULT      = '(* {} {})'
ADD       = '(+ {} {})'
EQ        = '(= {} {})'
FLGV      = 'm_{}_{}'
OR        = '(or {} {})'

D_TYPES = { 'Int': '(declare-const {} Int)\n',
            'Array': '(declare-const {} (Array Int Int))\n',}


def create_check_01(op1):
  eqs = [EQ.format(op1, i) for i in '01']
  return ASSERT.format(OR.format(eqs[0], eqs[1]))

def read_type(type_file):
    with open(type_file, 'r') as f:
        vtypes = []
        for line in f.readlines():
            vtypes.append(tuple(line.split()))
        return vtypes

def decl_vars(vlist, comment=';; Variable declarations.\n'):
  return comment + ''.join(D_TYPES[t].format(v) for v,t in vlist)
  
def check_flags_01(flags, comment=';; Check flags are either 0 or 1.\n'):
  return comment + ''.join(create_check_01(f) for f in flags)

def var2reg_map(vars, regs,
        comment=';; Each variable is mapped to one register\n'):
  assertions = []
  for v in vars:
    mstr = ''
    for r in regs:
      flg = FLGV.format(v,r)
      if mstr == '':
        mstr = flg
      else:
        mstr = ADD.format(mstr, flg)
    assertions.append(ASSERT.format(EQ.format(mstr, 1)))
  return comment + ''.join(assertions)

def reg2var_map(regs, vars,
        comment=';; Each register is mapped to exactly one variable.\n'):
  assertions = []
  for r in regs:
    mstr = ''
    for v in vars:
      flg = FLGV.format(v,r)
      if mstr == '':
        mstr = flg
      else:
        mstr = ADD.format(mstr, flg)
    assertions.append(ASSERT.format(EQ.format(mstr, 1)))
  return comment + ''.join(assertions)

def var2val_map(vars, regs, comment=';; Variable to values mapping.\n'):
  assertions = []
  for v in vars:
    mstr = ''
    for r in regs:
      flg = FLGV.format(v, r)
      mult = MULT.format(flg, r)
      if mstr == '':
        mstr = mult
      else:
        mstr = ADD.format(mstr, mult)
    assertions.append(ASSERT.format(EQ.format(v, mstr)))
  return comment + ''.join(assertions)

def val_reg_ass(vars, reg, comment=';; Variable to register assignments.\n'):
  return comment + ''.join(ASSERT.format(EQ.format(v, r)) for v,r in zip(vars,reg))

def value_mappings(vars, regs):
  asserts = [ var2reg_map(vars, regs),
              reg2var_map(regs, vars),
              var2val_map(vars, regs) ]
  return ''.join(asserts)

def get_vars(vfile):
  with open(vfile, 'r') as f:
    varlists = [line.split() for line in f.readlines()]
    return varlists[0], varlists[2], varlists[1], varlists[3]
  
def mk_parser(desc, flags, extflags, required, dest, actions, help):
  parser = argparse.ArgumentParser(description=desc)
  for flg, extflg, rq, dst, act, hlp in zip(flags, extflags, required, dest, actions, help):
    parser.add_argument(flg, extflg, dest=dst, required=rq, action=act, help=hlp)
  return parser

def write_str_list(fname, strlist):
  with open(fname, 'w') as f:
    for s in strlist:
      f.write(s)
      f.write('\n')

def append_files(fname, fnamelist, headstr):
  with open(fname, 'a') as ofile:
    for i, fname in enumerate(fnamelist):
      with open(fname, 'r') as infile:
        ofile.write(';; {} {}\n'.format(headstr, i+1))
        ofile.write(infile.read())
        ofile.write('\n')

def convsmt(vfile, hfile, args, cvars_input, cvars_intr, hvars_input, hvars_intr):
  flags = [(FLGV.format(v,r), 'Int')
          for v in cvars_intr for r in hvars_intr]
  vtype, htype = read_type(vfile), read_type(hfile)
  declarations = decl_vars(vtype+htype+flags)
  check_flags = check_flags_01(f[0] for f in flags)
  mappings = value_mappings(cvars_intr, hvars_intr)
  assignments = val_reg_ass(cvars_input, hvars_input)
  write_str_list(args.out,
          [declarations, check_flags, mappings, assignments])
  append_files(args.out, [args.csmt, args.hsmt], 'Program')

def main(argspecs):
  args = (mk_parser(description, *argspecs)).parse_args()
  (cvars_input, cvars_intr,
   hvars_input, hvars_intr) = get_vars(args.vfile)
  vfile, hfile = ( args.csmt.split('.smt')[0]+'.var',
                   args.hsmt.split('.smt')[0]+'.var' )
  csmt, hsmt = args.csmt, args.hsmt
  if args.timeit:
    timed_code = '''convsmt(vfile, hfile, args,
    cvars_input, cvars_intr, hvars_input, hvars_intr,)'''
    timed_globals = {'convsmt': convsmt, 'cvars_input': cvars_input,
      'cvars_intr': cvars_intr, 'hvars_input': hvars_input, 'args': args,
      'hvars_intr': hvars_intr, 'vfile': vfile, 'hfile': hfile}
    print('Time:', timeit.timeit(stmt = timed_code,
      globals=timed_globals, number=1), 'secs')
  else:
    convsmt(vfile, hfile, args, cvars_input, cvars_intr,
    hvars_input, hvars_intr)


if __name__ == '__main__':
  description = "Generate SMT program for checking equivalence of variables."
  argflags    = ['-s', '-r', '-v', '-o', '-t']
  extflags    = ['--cfile', '--hlsfile', '--vfile', '--outfile', '--timeit']
  required    = [True, True, True, True, False]
  dest        = ['csmt', 'hsmt', 'vfile', 'out', 'timeit']
  actions     = [None, None, None, None, 'store_true']
  help        = ['SMT program of the C source.',
                 'SMT of the HLS source.',
                 'File containing the list of variables.',
                 'File where the output will be written',
                 'Print the running time.']
  argspecs    = [argflags, extflags, required, dest, actions, help]
  main(argspecs)
