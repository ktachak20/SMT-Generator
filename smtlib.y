/* smtlib Parser */
/* Objectives:
    1. generate file containing variables declared. (DONE)
    2. generate two files, infile.smt and infile.var, from a single source file. (DONE)
*/

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXVARS 100
#define YYDEBUG 1

#define NT_EXP_ARR  257

FILE        *ofile_h;
FILE        *vfile_h;
char        *x;
char        *VR_vdec;              /* pointer to string of variable declarations. */
extern int  yyparse();
extern FILE *yyin;
int         varcount = 0;
char        *varlist[MAXVARS][2]; /* variable names and associated type */
int         vardef( void );
int         varcheck( char * );
char*       FN_mk_vdecl(char *, char *);
%}

%code requires {
  typedef struct { char *body; int type; } DATA_expr_t;
  DATA_expr_t *FN_mk_node( char *, int );
}

%union{
  int         TK_simple_t;
  char        *TK_literal_t;
  char        *TK_identifier_t;
  DATA_expr_t *NT_exp_t;
}

%type <NT_exp_t> primary_expression
%type <NT_exp_t> relational_operator
%type <NT_exp_t> primary_conditional_expression
%type <NT_exp_t> conditional_expression
%type <NT_exp_t> unary_expression
%type <NT_exp_t> expression
%type <NT_exp_t> assignment_expression
%type <NT_exp_t> assignments
%type <NT_exp_t> assignment_statement
%type <NT_exp_t> innerblock
%type <NT_exp_t> decision
%type <NT_exp_t> assertions
%type <NT_exp_t> mixed_statements
%type <NT_exp_t> postfix_expression
%type <NT_exp_t> unary_operator
%type <NT_exp_t> operator
%type <NT_exp_t> logical_operator

%type <TK_identifier_t> TK_ID
%type <TK_literal_t> TK_CT

%type <TK_simple_t> TK_IF
%type <TK_simple_t> TK_ELSE
%type <TK_simple_t> TK_CMM
%type <TK_simple_t> TK_LT_OP
%type <TK_simple_t> TK_GT_OP
%type <TK_simple_t> TK_LE_OP 
%type <TK_simple_t> TK_GE_OP 
%type <TK_simple_t> TK_EQ_OP 
%type <TK_simple_t> TK_NE_OP 
%type <TK_simple_t> TK_ASS_OP
%type <TK_simple_t> TK_LSQB
%type <TK_simple_t> TK_RSQB

%token TK_MU_OP  TK_DI_OP  TK_MO_OP
%token TK_NOT_OP TK_AND_OP TK_OR_OP
%token TK_LT_OP  TK_IMP_OP TK_GT_OP 
%token TK_ID     TK_CT     TK_CMM
%token TK_LB     TK_LP     TK_RB
%token TK_LE_OP  TK_GE_OP  TK_EQ_OP 
%token TK_IF     TK_ELSE   TK_ST_END
%token TK_LSQB   TK_RSQB   TK_RP
%token TK_PL_OP  TK_MI_OP
%token TK_NE_OP  TK_ASS_OP

%start smtlib

%left  TK_CMM
%left  TK_ASS_OP
%right TK_IMP_OP
%left  TK_OR_OP
%left  TK_AND_OP
%left  TK_NE_OP
%left  TK_EQ_OP
%left  TK_GE_OP
%left  TK_GT_OP
%left  TK_LE_OP
%left  TK_LT_OP
%left  TK_MI_OP
%left  TK_PL_OP
%left  TK_MO_OP
%left  TK_DI_OP
%left  TK_MU_OP
%nonassoc TK_NOT_OP
%nonassoc TK_IF
%nonassoc TK_ELSE

%%

primary_expression
  : TK_ID /* {varcheck($1);strcpy($$,$1); } */
    { $$ = FN_mk_node($1, TK_ID); }
  | TK_CT /*          {strcpy($$,$1); } */
    { $$ = FN_mk_node($1, TK_CT); }
  ;

postfix_expression
  : primary_expression
    { varcheck($1); $$ = $1; }
  | postfix_expression TK_LSQB expression TK_RSQB
    { 
      char *tmp;

      if( $1->type == TK_ID )
      {
        /* Check variable is already defined and set. */
        varcheck($1);
      }

      asprintf(&tmp, "(select %s %s)", $1->body, $3->body);
      $$ = FN_mk_node(tmp, NT_PST_EXP);
      free($1->body); free($3->body);
      free($1); free($3);
    }
  ;

unary_operator
  : TK_MI_OP
    { $$ = FN_mk_node("-", TK_MI_OP); }
  ;

unary_expression
  : postfix_expression
    { $$ = $1; }
  | unary_operator unary_expression
    {
        char *tmp;
        asprintf(&tmp, "(- %s)", $2);
        $$ = FN_mk_node(tmp, NT_UN_EXP);
    };

operator
  : TK_PL_OP   { $$ = FN_mk_node("+", TK_PL_OP); }
  | TK_MI_OP   { $$ = FN_mk_node("-", TK_MI_OP); }
  | TK_MU_OP   { $$ = FN_mk_node("*", TK_MU_OP); }
  | TK_DI_OP   { $$ = FN_mk_node("div", TK_DI_OP); }
  | TK_MO_OP   { $$ = FN_mk_node("mod", TK_MO_OP); }
  ;

expression
  : unary_expression
    { $$ = $1; }
  | expression operator expression
    { $$ = FN_gen_exp($1, $3, $2->type); }
  ;

assignment_expression
  : unary_expression TK_ASS_OP expression
    {
        char *exp;

        asprintf(&exp, "(= %s %s)", $1->body, $3->body);
        $$ = FN_mk_node(exp, NT_ASSN_EXP);

        free($1->body); free($1);
        free($3->body); free($3); /* replace with a macro */
    } 
  | TK_LB assignment_expression TK_RB
    { $$ = $2; }
  ;

relational_operator
  : TK_LT_OP   { $$ = FN_mk_node("<", TK_LT_OP); }
  | TK_GT_OP   { $$ = FN_mk_node(">", TK_GT_OP); }
  | TK_LE_OP   { $$ = FN_mk_node("<=", TK_LE_OP); }
  | TK_GE_OP   { $$ = FN_mk_node(">=", TK_GE_OP); }
  | TK_EQ_OP   { $$ = FN_mk_node("=", TK_GE_OP); } /*== operator*/
  | TK_NE_OP   { $$ = FN_mk_node("neq", TK_NE_OP); }
  | TK_ASS_OP  { $$ = FN_mk_node("=", TK_NE_OP); }
  ;

primary_conditional_expression
  : expression relational_operator expression
    { $$ = FN_gen_exp($1, $3, $2->type); NODE_free($2); }
  ;

logical_operator:   TK_AND_OP { $$ = FN_mk_node("and", TK_AND_OP); }
                |   TK_OR_OP  { $$ = FN_mk_node("or", TK_OR_OP); }
                |   TK_IMP_OP { $$ = FN_mk_node("=>", TK_IMP_OP); }
                |   TK_EQ_OP  { $$ = FN_mk_node("=", TK_EQ_OP); }
                ;

conditional_expression: primary_conditional_expression
                        { $$ = $1; }
                      | TK_NOT_OP conditional_expression
                        { $$ = FN_gen_exp_unary($2, TK_NOT_OP); }
                      | conditional_expression logical_operator conditional_expression
                        { $$ = FN_gen_exp($1, $3, $2->type); NODE_free($2); }
                      | TK_LB conditional_expression TK_RB
                        { $$ = $2; }
                      ;

assignment_statement: assignment_expression TK_ST_END { $$ = $1; }
                    ;

assignments: assignment_statement             { $$ = $1; }
           | assignment_statement assignments { $$ = FN_gen_conjunc($1, $2); }
           ;

mixed_statements: assignments { $$ = $1; }
                | decision    { $$ = $1; }
                | assignments mixed_statements { $$ = FN_gen_conjunc($1, $2); }
                | decision mixed_statements    { $$ = FN_gen_conjunc($1, $2); }
                ;

innerblock: assignment_statement         { $$ = $1; }
          | decision                     { $$ = $1; }
          | TK_LP mixed_statements TK_RP { $$ = $2; }
          ;

decision: TK_IF conditional_expression innerblock 
          { $$ = FN_gen_impl($2, $3, NULL); }
        | TK_IF conditional_expression innerblock TK_ELSE innerblock
          { $$ = FN_gen_impl($2, $3, $5); }
        ;

assertions: assignment_statement { $$ = FN_gen_assert($1); }
          | assignment_statement assertions
            {
                char *assrt;
                asprintf(&assrt, "(assert %s)\n%s)", $1->body, $2->body);
                NODE_free($1); NODE_free($2);
                $$ = FN_mk_node(assrt, NT_ASSRT);
            }
          | decision    { $$ = FN_gen_assert($1); }
          | decision assertions
            {
                char *assrt;
                asprintf(&assrt, "(assert %s)\n%s)", $1->body, $2->body);
                NODE_free($1); NODE_free($2);
                $$ = FN_mk_node(assrt, NT_ASSRT);
            }
          ;
smtlib:
        assertions { vardef(); FN_write_node_to_file(ofile, $1); NODE_free($1); }
      ;

%%

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
   exit(0);
}


int callSMTLIBparser( char *ifile )
{       
  char *vfile, *ofile;
        yyin = fopen( ifile ,"r");
        if(yyin==NULL)
                return 0;
  asprintf( &ofile, "%s.smt", ifile );
        ofile_h = fopen( ofile, "w" );
  asprintf( &vfile, "%s.var", ifile );
  vfile_h = fopen( vfile, "w" );
        if(yyparse())
        {       
                printf("Error\n");
                return 0;       
        }
        fclose(yyin);
        fclose(ofile_h);
  free( ofile );
  free( vfile );
  return 0;
}

int varcheck(char *var)
{
  int i=0;
  if(varcount>0)
  {
    for(i=0;i<varcount;i++)
    {
      if(!strcmp(varlist[i],var)) // Variable Name is already in list
      return 0;
    }
  } 
  varlist[i]=var;
  varcount++;
  return 1;
}

int vardef()
{
  int i=0;
  while(i<varcount-1)
  {
      fprintf(vfile_h,"%s ",varlist[i]);
      i++;
  }
  fprintf(vfile_h, "%s", varlist[i]);
  return 1;
}

DATA_expr_t* FN_mk_node(char *s, int type)
{
  DATA_expr_t *node = malloc(sizeof(DATA_expr_t));
  node->body = s;
  node->type = type;

  return node;
}

char* FN_mk_vdecl(char *v, char *v_t)
{
  char *decl;
  asprintf(&decl, "(declare-const %s %s)\n", v, v_t);
  return decl;
}

DATA_expr_t* FN_gen_exp(DATA_expr_t *nleft, DATA_expr_t *nright, int op_t)
{
    char *exp;

    switch(op_t)
    {
    case TK_PL_OP:
        asprintf(&exp, "(+ %s %s)", nleft->body, rleft->body);
        break;
    case TK_MI_OP:
        asprintf(&exp, "(- %s %s)", nleft->body, rleft->body);
        break;
    case TK_MU_OP:
        asprintf(&exp, "(* %s %s)", nleft->body, rleft->body);
        break;
    case TK_DI_OP:
        asprintf(&exp, "(mod %s %s)", nleft->body, rleft->body);
        break;
    case TK_MO_OP:
        asprintf(&exp, "(mod %s %s)", nleft->body, rleft->body);
        break;
    case TK_LT_OP:
        asprintf(&exp, "(< %s %s)", nleft->body, rleft->body);
        break;
    case TK_GT_OP:
        asprintf(&exp, "(> %s %s)", nleft->body, rleft->body);
        break;
    case TK_LE_OP:
        asprintf(&exp, "(<= %s %s)", nleft->body, rleft->body);
        break;
    case TK_GE_OP:
        asprintf(&exp, "(>= %s %s)", nleft->body, rleft->body);
        break;
    case TK_NE_OP:
        asprintf(&exp, "(not (= %s %s))", nleft->body, rleft->body);
        break;
    case TK_IMP:
        asprintf(&exp, "(=> %s %s)", nleft->body, rleft->body);
        break;
    default:
        printf("\nInvalid syntax: Operator no recognized!\n");
        exit(-1); break;

    free(nleft->body); free(nleft);
    free(rleft->body); free(rleft);

    return FN_mk_node(exp, NT_EXP);
}

DATA_expr_t* FN_gen_conjunc(DATA_expr_t *nstart, DATA_expr_t *nend)
{
    char *assn;
    asprintf(&assn, "(and %s %s)", nstart->body, nend->body);
    NODE_free(nstart); NODE_free(nend);

    return FN_mk_node(assn, NT_CONJ);
}

DATA_expr_t* FN_gen_impl(DATA_expr_t *ncond, DATA_expr_t *nbranch1, DATA_expr_t *nbranch2)
{
    char *impl;

    if( nbranch2 == NULL )
    {
        asprintf(&impl, "(ite %s %s (= 1 1))", ncond->body, nbranch1);
    }
    else
    {
        asprintf(&impl, "(ite %s %s %s)", ncond->body, nbranch1->body, nbranch2->body);
    }

    NODE_free(ncond); NODE_free(nconclusion);
    return FN_mk_node(impl, NT_IMPL);
}

DATA_expr_t* FN_gen_assert(DATA_expr_t *stmt)
{
    char *assert;
    asprintf(&assert, "(assert %s)", stmt->body);
    NODE_free(stmt);
    return FN_mk_node(assert, NT_ASSRT);
}

void FN_write_node_to_file(DATA_expr_t *node, char *fname)
{
    FILE *fname_h = fopen(fname, "w");
    fprintf(fname_h, "%s", node->body);
}
