#!/usr/bin/env python
from __future__ import print_function

import sys
import argparse

from collections import OrderedDict

DEC_CONST = '(declare-const {var} {type})'
ASSERT    = '(assert {exp})'
MULT      = '(* {op1} {op2})'
ADD       = '(+ {op1} {op2})'
EQ        = '(= {op1} {op2})'
FLGV      = 'm_{v1}_{v2}'
OR        = '(or {op1} {op2})'

def create_decl(var, type='Int'):
  return DEC_CONST.format( var=var, type=type) + '\n'

def create_assert(exp):
  return ASSERT.format(exp=exp) + '\n'

def create_eq(op1, op2):
  return EQ.format(op1=op1, op2=op2)

def create_check_01(op1):
  eqs = [EQ.format(op1, i) for i in '01']
  return create_assert(OR.format(eqs[0], eqs[1]))

def decl_vars(vlist, comment=';; Variable declarations.\n'):
  return comment + ''.join(create_decl(v) for v in vlist)
  
def check_flags_01(flags, comment=';; Check flags are either 0 or 1.\n'):
  return comment + ''.join(create_assert(create_check_01(f)) for f in flags)

def var2reg_map(vars, regs, comment=';; Variable to register mapping.\n'):
  assertions = []
  for v in vars:
    mstr = ''
    for r in regs:
      if mstr == '':
        mstr = FLGV.format(v1=v,v2=r)
      else:
        mstr = ADD.format(op1=mstr, op2=FLGV.format(v1=v,v2=r))
    assertions.append(create_assert(EQ.format(op1=mstr,op2=1)))
  return comment + ''.join(assertions)

def reg2var_map(regs, vars, comment=';; Register to variable mapping.\n'):
  assertions = []
  for r in regs:
    mstr = ''
    for v in vars:
      if mstr == '':
        mstr = FLGV.format(v1=v,v2=r)
      else:
        mstr = ADD.format(op1=mstr, op2=FLGV.format(v1=v,v2=r))
    assertions.append(create_assert(EQ.format(op1=mstr,op2=1)))
  return comment + ''.join(assertions)

def var2val_map(vars, regs, comment=';; Variable to values mapping.\n'):
  assertions = []
  for v in vars:
    mstr = ''
    for r in regs:
      flg = FLGV.format(v1=v,v2=r)
      mult = MULT.format(op1=flg, op2=r)
      if mstr == '':
        mstr = mult
      else:
        mstr = ADD.format(op1=mstr, op2=mult)
    assertions.append(create_assert(EQ.format(op1=v,op2=mstr)))
  return comment+''.join(assertions)

def val_reg_ass(vars, reg, comment=';; Variable to register assignments.\n'):
  return comment+''.join(create_assert(EQ.format(op1=v,op2=r)) for v,r in zip(vars,reg))

def value_mappings(vars, regs):
  asserts = [ var2reg_map(vars, regs),
              reg2var_map(regs, vars),
              var2val_map(vars, regs) ]
  return ''.join(asserts)


if __name__ == '__main__':
  parser = argparse.ArgumentParser(description="Generate SMT program for checking equivalence of variables.")
  parser.add_argument('-s', '--cfile', help='SMT program of the C source.', dest='csmt', required=True)
  parser.add_argument('-r', '--hlsfile', help='SMT of the HLS source.', dest='hsmt', required=True)
  parser.add_argument('-v', '--vfile', help='File containing the list of variables.', required=True)
  parser.add_argument('-o', '--outfile', help='File where the output will be written', default='out.txt', dest='out')
  
  args = parser.parse_args()
  
  cvars_input, cvars_intr = [], []
  hvars_input, hvars_intr = [], []
  with open(args.vfile, 'r') as vfile:
    # first line contains input variables in csmt.
    line = vfile.readline()
    cvars_input = line.split()
    line = vfile.readline()
    hvars_input = line.split()
    line = vfile.readline()
    cvars_intr = line.split()
    line = vfile.readline()
    hvars_intr = line.split()
  flags = [FLGV.format(v1=v,v2=r) for v in cvars_intr for r in hvars_intr]
  declarations = decl_vars(cvars_input+cvars_intr+hvars_input+hvars_intr+flags)
  mappings = value_mappings(cvars_intr, hvars_intr)
  assignments = val_reg_ass(cvars_input, hvars_input)
  with open(args.out, 'w') as ofile:
    ofile.write(declarations)
    ofile.write('\n')
    ofile.write(assignments)
    ofile.write('\n')
    ofile.write(mappings)
    ofile.write('\n')
    with open(args.csmt, 'r') as cfile:
      ofile.write(';; Program 1\n')
      ofile.write(cfile.read())
    ofile.write('\n')
    with open(args.hsmt, 'r') as hfile:
      ofile.write(';; Program 2\n')
      ofile.write(hfile.read())
