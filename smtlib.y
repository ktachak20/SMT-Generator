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
char        *varlist[MAXVARS];
int         vardef( void );
int         varcheck( char * );
char*       FN_mk_vdecl(char *, char *);
%}

%code requires {
  typedef struct { char *body; int type; } DATA_expr_t;
  DATA_expr_t *FN_mk_node( char *, int );
}

%union{
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
%token TK_ID 	 TK_CT 	   TK_CMM
%token TK_LB 	 TK_LP 	   TK_RB
%token TK_LE_OP  TK_GE_OP  TK_EQ_OP 
%token TK_IF 	 TK_ELSE   TK_ST_END
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
    {
      varcheck($1); $$ = FN_mk_node($1, TK_ID);
      /* Required for variable declaration 
      char *tmp = VR_vdecl; VR_vdecl = NULL;
      asprintf(&VR_vdecl, "%s%s", tmp, FN_mk_vdecl($1, "Int");
      free(tmp);
      */
    }
  | TK_CT /*          {strcpy($$,$1); } */
    { $$ = FN_mk_node($1, TK_CT); }
;

postfix_expression
  : primary_expression
    { $$ = $1; }
  | postfix_expression TK_LSQB expression TK_RSQB
    { 
      char *tmp;
      asprintf(&tmp, "(select %s %s)", $1->body, $3->body);
      $$ = FN_mk_node(tmp, NT_EXP_ARR);
      free($1->body); free($3->body);
      free($1); free($3);
    }
  ;

unary_expression
  : postfix_expression
    { $$ = $1; }
  | TK_MI_OP primary_expression %prec TK_UMI
    {
        char *tmp;
        asprintf(&tmp, "(- %s)", $2);
        $$ = FN_mk_node(tmp, TK_MI_OP);
    };

expression
  : unary_expression              { $$ = $1; }
  | expression TK_PL_OP expression
    { 
      int size = asprintf(&x, "%s%s%s%s%s", "(+ ", $1," ", $3,")" );
      $$=x;
    }
  | expression TK_MI_OP expression
    { 
      int size = asprintf(&x, "%s%s%s%s%s", "(- ", $1," ", $3,")" );
      $$=x;
    }
  | TK_LB TK_DI_OP expression TK_CMM expression TK_RB
    { 
      int size = asprintf(&x, "%s%s%s%s%s", "(div ", $3," ", $5,")" );
      $$=x;
    }
  | TK_LB TK_MO_OP expression TK_CMM expression TK_RB
    { 
      int size = asprintf(&x, "%s%s%s%s%s", "(mod ", $3," ", $5,")" );
      $$=x;
    }
  | expression TK_MU_OP expression
    { 
      int size = asprintf(&x, "%s%s%s%s%s", "(* ", $1," ", $3,")" );
      $$=x;
    }
  | TK_LB expression TK_RB {$$=$2;};
  ;

assignment_expression
  : unary_expression TK_ASS_OP expression{  
      char *x;
      int size = asprintf(&x, "%s%s%s%s%s", "(= ", $1," ", $3,")" );
      $$=x;
    }
  | TK_LB assignment_expression TK_RB {$$=$2;};
  ;
relational_operator
  : TK_LT_OP   { strcpy($$,$1); }
  | TK_GT_OP   { strcpy($$,$1); }
  | TK_LE_OP   { strcpy($$,$1); }
  | TK_GE_OP   { strcpy($$,$1); }
  | TK_EQ_OP   { strcpy($$,"="); } /*== operator*/
  | TK_NE_OP   { strcpy($$,$1); }
  | TK_ASS_OP   { strcpy($$,$1); }
  ;

primary_conditional_expression
  : expression relational_operator expression{
      int size;
      if(strcmp($2,"!=")==0)
      size = asprintf(&x, "%s%s%s%s%s%s", "(not (="," ",$1," ", $3,"))");
      else
      size = asprintf(&x, "%s%s%s%s%s%s%s", "(",$2," ",$1," ", $3,")");
      $$=x;
    }
  ;

conditional_expression
  : primary_conditional_expression  { $$ = $1; }
  | conditional_expression TK_AND_OP conditional_expression 
    {
      int size = asprintf(&x, "%s%s%s%s%s", "(and ", $1," ", $3,")" );
      $$=x;
    }
  | conditional_expression TK_IMP_OP conditional_expression 
    {
      int size = asprintf(&x, "%s%s%s%s%s", "(=> ", $1," ", $3,")" );
      $$=x;
    } 
  | conditional_expression TK_OR_OP conditional_expression
    {
      int size = asprintf(&x, "%s%s%s%s%s", "(or ", $1," ", $3,")" );
      $$=x;
    }
  | conditional_expression TK_EQ_OP conditional_expression 
    {
      int size = asprintf(&x, "%s%s%s%s%s", "(= ", $1," ", $3,")" );
      $$=x;
    }

  | TK_LB conditional_expression TK_RB   { $$ = $2; }

  |TK_NOT_OP TK_LB conditional_expression TK_RB    
    {
      int size = asprintf(&x, "%s%s%s", "(not ",$3,")" );
      $$=x;
    }
  ;

/* COMMENTED: by ktachak 191219
assignment_list
	: assignment_list assignment_expression 
	{
		int size=asprintf(&x, "(and %s %s)",$1,$2);
	 	$$=x;

	}| 
	assignment_expression
	{
	 	$$=$1;	
	}
;
*/

/* AUTHOR: ktachak 191219 */
assignment_statement: assignment_expression TK_ST_END { $$ = $1; }
                    ;
assignments: assignment_statement   { $$ = $1; }
           | assignment_statement assignments
             { asprintf( &x, "(and %s %s)", $1, $2 ); $$ = x; }
           ;
mixed_statements: assignments { $$ = $1; }
                | decision    { $$ = $1; }
                | assignments mixed_statements 
                  { asprintf( &x, "(and %s %s)", $1, $2 ); $$ = x; }
                | decision mixed_statements 
                  { asprintf( &x, "(and %s %s)", $1, $2 ); $$ = x; }
                ;
innerblock: assignment_statement         { $$ = $1; }
          | decision                     { $$ = $1; }
          | TK_LP mixed_statements TK_RP { $$ = $2; }
          ;
decision: TK_IF conditional_expression innerblock 
          { asprintf( &x, "(ite %s %s true)", $2, $3 ); $$ = x; }
        | TK_IF conditional_expression innerblock TK_ELSE innerblock
          { asprintf( &x, "(ite %s %s %s)", $2, $3, $5 ); $$ = x; }
        ;
assertions: assignment_statement { asprintf( &x, "(assert %s)", $1 ); $$ = x; }
          | decision    { asprintf( &x, "(assert %s)", $1 ); $$ = x; }
          | assignment_statement assertions
            { asprintf( &x, "(assert %s)\n%s", $1, $2 ); $$ = x; }
          | decision assertions
            { asprintf( &x, "(assert %s)\n%s", $1, $2 ); $$ = x; }
          ;
smtlib:
        assertions { vardef(); asprintf( &x, "%s\n", $1 ); fprintf( ofile_h, "%s", x ); }
      ;
/* ktachak 191219 */

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
