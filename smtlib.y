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

#define NT_ARR_EXP  10
#define NT_PST_EXP  11
#define NT_UN_EXP   12
#define NT_ASSN_EXP 13
#define NT_ASSRT    14
#define NT_EXP      15
#define NT_CONJ     16
#define NT_IMPL     18

#define NODE_free(n) \
    free((n)->body); free(n)

typedef struct _DATA_expr_t { char *body; int type; } DATA_expr_t;

char        *ofile;
char        *vfile;
int         varcount = 0;
DATA_expr_t *varlist[MAXVARS]; /* variable names and associated type */

extern int  yylex();
extern int  yyparse();
extern FILE *yyin;
extern void yyerror( const char * );

extern int  FN_smtlib_parse( const char * );
int         FN_vardef( void );
void        FN_varcheck( DATA_expr_t * );
char        *FN_mk_vdecl(char *, char *);
DATA_expr_t *FN_mk_node( const char *, int );
void        FN_write_node_to_file( DATA_expr_t *, char *);
DATA_expr_t *FN_gen_assert( DATA_expr_t *stmt );
DATA_expr_t *FN_gen_impl( DATA_expr_t *ncond, DATA_expr_t *nbranch1, DATA_expr_t *nbranch2 );
DATA_expr_t *FN_gen_conjunc( DATA_expr_t *nstart, DATA_expr_t *nend );
DATA_expr_t *FN_gen_exp( DATA_expr_t *nleft, DATA_expr_t *nright, int op_t );
DATA_expr_t *FN_gen_exp_unary( DATA_expr_t *, int );
char        *FN_get_var_type( DATA_expr_t * );
%}

%code requires{
    typedef struct _DATA_expr_t DATA_expr_t;
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
  : TK_ID
    { printf("EXP: primary\n"); $$ = FN_mk_node($1, TK_ID); }
  | TK_CT
    { printf("EXP: primary\n"); $$ = FN_mk_node($1, TK_CT); }
  ;

postfix_expression: primary_expression
                    { 
                        printf("EXP: postfix 1\n");
                        if( $1->type == TK_ID )
                        {
                            FN_varcheck($1);
                        }
                        $$ = $1;
                    }
                  | postfix_expression TK_LSQB expression TK_RSQB
                    {
                        printf("EXP: postfix 2\n");
                        char *tmp;
                  
                        if( $1->type == TK_ID )
                        {
                          /* Check variable is already defined and set. */
                          $1->type = NT_ARR_EXP;
                          FN_varcheck($1);
                        }
                  
                        asprintf(&tmp, "(select %s %s)", $1->body, $3->body);
                        $$ = FN_mk_node(tmp, NT_PST_EXP);
                        NODE_free($1); NODE_free($3);
                    }
                  ;

unary_operator
  : TK_MI_OP
    { printf("EXP: unary_op \n"); $$ = FN_mk_node("-", TK_MI_OP); }
  ;

unary_expression
  : postfix_expression
    { printf("EXP: unary_exp \n"); $$ = $1; }
  | unary_operator unary_expression
    { printf("EXP: unary_exp \n"); $$ = FN_gen_exp_unary($2, $1->type); NODE_free($1); }
  ;

operator:   TK_PL_OP
            { 
                printf("EXP: op1 \n");
                char *op; asprintf(&op, "+");
                $$ = FN_mk_node(op, TK_PL_OP);
            }
        |   TK_MI_OP
            { 
                printf("EXP: op2 \n");
                char *op; asprintf(&op, "-");
                $$ = FN_mk_node(op, TK_PL_OP);
            }
        |   TK_MU_OP
            { 
                printf("EXP: op3 \n");
                char *op; asprintf(&op, "*");
                $$ = FN_mk_node(op, TK_PL_OP);
            }
        |   TK_DI_OP
            { 
                printf("EXP: op4 \n");
                char *op; asprintf(&op, "div");
                $$ = FN_mk_node(op, TK_PL_OP);
            }
        |   TK_MO_OP
            { 
                printf("EXP: op5 \n");
                char *op; asprintf(&op, "mod");
                $$ = FN_mk_node(op, TK_PL_OP);
            }
        ;

expression
  : unary_expression
    { printf("EXP: exp1\n"); $$ = $1; }
  | expression operator expression
    { printf("EXP: exp2\n"); $$ = FN_gen_exp($1, $3, $2->type); NODE_free($2); printf("EXP: exp2.1\n"); }
  ;

assignment_expression
  : unary_expression TK_ASS_OP expression
    {printf("EXP: assn_exp \n");
        char *exp;

        asprintf(&exp, "(= %s %s)", $1->body, $3->body);
        $$ = FN_mk_node(exp, NT_ASSN_EXP);

        NODE_free($1); NODE_free($3);
    } 
  | TK_LB assignment_expression TK_RB
    { printf("EXP: assn_exp \n"); $$ = $2; }
  ;

relational_operator
  : TK_LT_OP   {printf("EXP: rel_op1 \n"); char *op; asprintf(&op, "<"); $$ = FN_mk_node(op, TK_LT_OP); }
  | TK_GT_OP   {printf("EXP: rel_op2 \n"); char *op; asprintf(&op, ">"); $$ = FN_mk_node(op, TK_GT_OP); }
  | TK_LE_OP   {printf("EXP: rel_op3 \n"); char *op; asprintf(&op, "<="); $$ = FN_mk_node(op, TK_LE_OP); }
  | TK_GE_OP   {printf("EXP: rel_op4 \n"); char *op; asprintf(&op, ">="); $$ = FN_mk_node(op, TK_GE_OP); }
  | TK_EQ_OP   {printf("EXP: rel_op5 \n"); char *op; asprintf(&op, "="); $$ = FN_mk_node(op, TK_GE_OP); } /*== operator*/
  | TK_NE_OP   {printf("EXP: rel_op6 \n"); char *op; asprintf(&op, "!="); $$ = FN_mk_node(op, TK_NE_OP); }
  | TK_ASS_OP  {printf("EXP: rel_op7 \n"); char *op; asprintf(&op, "="); $$ = FN_mk_node(op, TK_NE_OP); }
  ;

primary_conditional_expression
  : expression relational_operator expression
    { printf("EXP: prim_cond_exp1\n"); $$ = FN_gen_exp($1, $3, $2->type); NODE_free($2); }
  ;     
        
logical_operator:   TK_AND_OP { printf("EXP: log_op1\n"); $$ = FN_mk_node("and", TK_AND_OP); }
                |   TK_OR_OP  { printf("EXP: log_op1\n"); $$ = FN_mk_node("or", TK_OR_OP); }
                |   TK_IMP_OP { printf("EXP: log_op1\n"); $$ = FN_mk_node("=>", TK_IMP_OP); }
                |   TK_EQ_OP  { printf("EXP: log_op1\n"); $$ = FN_mk_node("=", TK_EQ_OP); }
                ;

conditional_expression: primary_conditional_expression
                        { printf("EXP: cond_exp1\n"); $$ = $1; }
                      | TK_NOT_OP conditional_expression
                        { printf("EXP: cond_exp2\n"); $$ = FN_gen_exp_unary($2, TK_NOT_OP); }
                      | conditional_expression logical_operator conditional_expression
                        { printf("EXP: cond_exp3\n"); $$ = FN_gen_exp($1, $3, $2->type); NODE_free($2); }
                      | TK_LB conditional_expression TK_RB
                        { printf("EXP: cond_exp4\n"); $$ = $2; }
                      ;

assignment_statement: assignment_expression TK_ST_END { printf("EXP: assn_st1\n"); $$ = $1; }
                    ;

assignments: assignment_statement             { printf("EXP: assn1\n"); $$ = $1; }
           | assignment_statement assignments { printf("EXP: assn2\n"); $$ = FN_gen_conjunc($1, $2); }
           ;

mixed_statements: assignments { printf("EXP: mix_st1\n"); $$ = $1; }
                | decision    { printf("EXP: mix_st2\n"); $$ = $1; }
                | assignments mixed_statements { printf("EXP: mix_st3\n"); $$ = FN_gen_conjunc($1, $2); }
                | decision mixed_statements    { printf("EXP: mix_st4\n"); $$ = FN_gen_conjunc($1, $2); }
                ;

innerblock: assignment_statement         { printf("EXP: innblock1\n"); $$ = $1; }
          | decision                     { printf("EXP: innblock2\n"); $$ = $1; }
          | TK_LP mixed_statements TK_RP { printf("EXP: innblock3\n"); $$ = $2; }
          ;

decision: TK_IF conditional_expression innerblock 
          { printf("EXP: deci1\n"); $$ = FN_gen_impl($2, $3, NULL); }
        | TK_IF conditional_expression innerblock TK_ELSE innerblock
          { printf("EXP: deci2\n"); $$ = FN_gen_impl($2, $3, $5); }
        ;

assertions: assignment_statement { printf("EXP: asst1\n"); $$ = FN_gen_assert($1); }
          | assignment_statement assertions
            {printf("EXP: asst2\n");
                char *assrt;
                asprintf(&assrt, "(assert %s)\n%s", $1->body, $2->body);
                NODE_free($1); NODE_free($2);
                $$ = FN_mk_node(assrt, NT_ASSRT);
            }
          | decision    { printf("EXP: asst3\n"); $$ = FN_gen_assert($1); }
          | decision assertions
            {printf("EXP: asst4\n");
                char *assrt;
                asprintf(&assrt, "(assert %s)\n%s", $1->body, $2->body);
                NODE_free($1); NODE_free($2);
                $$ = FN_mk_node(assrt, NT_ASSRT);
            }
          ;

smtlib: assertions
        { printf("EXP: smtlib\n"); FN_vardef(); FN_write_node_to_file($1, ofile); NODE_free($1); }
      ;

%%

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
}

int FN_smtlib_parse(const char *ifile )
{       
    yyin = fopen( ifile ,"r");

    if(yyin==NULL) return -1;
    
    asprintf( &ofile, "%s.smt", ifile );
    asprintf( &vfile, "%s.var", ifile );
    if(yyparse())
    {       
        printf("Error\n");
        return -1;
    }
    fclose(yyin);
    free( ofile );
    free( vfile );
    return 0;
}

void FN_varcheck(DATA_expr_t *node)
{
  int i = 0;

  printf("DEBUG: no error FN_varcheck 1\n");
  if( varcount > 0 )
  {
    for( ; i < varcount ; i++ )
    {
      printf("DEBUG: no error FN_varcheck 2.%d.0\n", i);
      if( !strcmp(varlist[i]->body, node->body) ) // Variable Name is already in list
      {
        if( varlist[i]->type != node->type )
        {
            printf("\nTypeError: Redefining a variable to different type!\n");
            exit(-1);
        }
        return;
      }
      printf("DEBUG: no error FN_varcheck 2.%d.1\n", i);
    }
  } 
  /* varlist[i] = var; */
  printf("DEBUG: no error FN_varcheck 3\n");
  varlist[i] = FN_mk_node(node->body, node->type);
  varcount++;
  printf("DEBUG: no error FN_varcheck 4\n");
  return;
}

char* FN_get_var_type(DATA_expr_t *v)
{
    char *type;

    switch(v->type)
    {
    case TK_ID:
        asprintf(&type, "%s Int", v->body);
        break;
    case NT_ARR_EXP:
        asprintf(&type, "%s Array", v->body);
        break;
    default:
        printf("\nDEBUG: %s, of type %d\n", v->body, v->type);
        printf("TypeError: Unknown type declared!\n");
        exit(-1);
        break;
    }
    return type;
}

int FN_vardef()
{
  int i = 0;
  char *vmap;

  FILE *vfile_h = fopen(vfile, "w");
  printf("DEBUG: FN_vardef, variable file %s\n", vfile);
  while( i<varcount-1 )
  {
      printf("DEBUG: no error in FN_vardef 0.0\n");
      vmap = FN_get_var_type(varlist[i]);
      printf("DEBUG: no error in FN_vardef 0.1\n");
      fprintf(vfile_h, "%s\n", vmap);
      printf("DEBUG: no error in FN_vardef 0.2\n");
      NODE_free(varlist[i]);
      printf("DEBUG: no error in FN_vardef 0.3\n");
      i++;
  }
  printf("DEBUG: no error in FN_vardef 1\n");
  vmap = FN_get_var_type(varlist[i]);
  printf("DEBUG: no error in FN_vardef 2\n");
  fprintf(vfile_h, "%s\n", vmap);
  printf("DEBUG: no error in FN_vardef 3\n");
  NODE_free(varlist[i]);
  printf("DEBUG: no error in FN_vardef 4\n");
  return 1;
}

DATA_expr_t* FN_mk_node(const char *s, int type)
{
  DATA_expr_t *node = malloc(sizeof(DATA_expr_t));
  asprintf(&(node->body), "%s", s);
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
        asprintf(&exp, "(+ %s %s)", nleft->body, nright->body);
        break;
    case TK_MI_OP:
        asprintf(&exp, "(- %s %s)", nleft->body, nright->body);
        break;
    case TK_MU_OP:
        asprintf(&exp, "(* %s %s)", nleft->body, nright->body);
        break;
    case TK_DI_OP:
        asprintf(&exp, "(mod %s %s)", nleft->body, nright->body);
        break;
    case TK_MO_OP:
        asprintf(&exp, "(mod %s %s)", nleft->body, nright->body);
        break;
    case TK_LT_OP:
        asprintf(&exp, "(< %s %s)", nleft->body, nright->body);
        break;
    case TK_GT_OP:
        asprintf(&exp, "(> %s %s)", nleft->body, nright->body);
        break;
    case TK_LE_OP:
        asprintf(&exp, "(<= %s %s)", nleft->body, nright->body);
        break;
    case TK_GE_OP:
        asprintf(&exp, "(>= %s %s)", nleft->body, nright->body);
        break;
    case TK_NE_OP:
        asprintf(&exp, "(not (= %s %s))", nleft->body, nright->body);
        break;
    default:
        printf("\nInvalid syntax: Operator no recognized!\n");
        exit(-1); break;
    }

    printf("DEBUG: no error FN_gen_exp 1\n");
    NODE_free(nleft); NODE_free(nright);
    printf("DEBUG: no error FN_gen_exp 2\n");

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
        asprintf(&impl, "(ite %s %s (= 1 1))", ncond->body, nbranch1->body);
        NODE_free(ncond); NODE_free(nbranch1);
    }
    else
    {
        asprintf(&impl, "(ite %s %s %s)", ncond->body, nbranch1->body, nbranch2->body);
        NODE_free(ncond); NODE_free(nbranch1); NODE_free(nbranch2);
    }

    return FN_mk_node(impl, NT_IMPL);
}

DATA_expr_t* FN_gen_assert(DATA_expr_t *stmt)
{
    char *assert;
    asprintf(&assert, "(assert %s)", stmt->body);
    printf("DEBUG: no error FN_gen_assert1\n");
    NODE_free(stmt);
    printf("DEBUG: no error FN_gen_assert2\n");
    return FN_mk_node(assert, NT_ASSRT);
}

void FN_write_node_to_file(DATA_expr_t *node, char *fname)
{
    printf("DEBUG: no error FN_write_node_to_file 1\n");
    FILE *fname_h = fopen(fname, "w");
    printf("DEBUG: no error FN_write_node_to_file 2\n");
    fprintf(fname_h, "%s", node->body);
}

DATA_expr_t* FN_gen_exp_unary( DATA_expr_t *arg, int op_t)
{
    char *exp;

    switch(op_t)
    {
    case TK_MI_OP:
        asprintf(&exp, "(* -1 %s)", arg->body);
        break;
    default:
        printf("\nInvalid Syntax: operator no recognized!\n");
        break;
    }
    NODE_free(arg);
    return FN_mk_node(exp, NT_EXP);
}
