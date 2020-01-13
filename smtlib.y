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

FILE        *ofile_h;
FILE        *vfile_h;
char        *x;
extern int  yyparse();
extern FILE *yyin;
int         varcount = 0;
char        *varlist[MAXVARS];
int         vardef( void );
int         varcheck( char * );
%}

%union{
  char* string;
}

%type <string> primary_expression
%type <string> relational_operator
%type <string> primary_conditional_expression
%type <string> conditional_expression
%type <string> unary_expression
%type <string> expression
%type <string> assignment_expression
%type <string> assignments
%type <string> assignment_statement
%type <string> innerblock
%type <string> decision
%type <string> assertions
%type <string> mixed_statements
%type <string> postfix_expression
%type <string> TK_ID
%type <string> TK_IF
%type <string> TK_ELSE
%type <string> TK_CMM
%type <string> TK_CT
%type <string> TK_LT_OP
%type <string> TK_GT_OP
%type <string> TK_LE_OP 
%type <string> TK_GE_OP 
%type <string> TK_EQ_OP 
%type <string> TK_NE_OP 
%type <string> TK_ASS_OP
%type <string> TK_LSQB
%type <string> TK_RSQB

%token TK_MU_OP
%token TK_PL_OP 
%token TK_UMI
%token TK_LT_OP 
%token TK_NOT_OP
%token TK_AND_OP
%token TK_OR_OP
%token TK_IMP_OP
%token TK_ID
%token TK_CT
%token TK_CMM
%token TK_LB 
%token TK_LP 
%token TK_RB
%token TK_RP
%token TK_GT_OP 
%token TK_LE_OP  
%token TK_GE_OP 
%token TK_EQ_OP 
%token TK_NE_OP 
%token TK_ASS_OP
%token TK_MI_OP
%token TK_DI_OP 
%token TK_MO_OP
%token TK_IF
%token TK_ELSE
%token TK_ST_END
%token TK_LSQB
%token TK_RSQB

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
%nonassoc TK_UMI
%nonassoc TK_IF
%nonassoc TK_ELSE

%%

primary_expression
  :TK_ID {varcheck($1);strcpy($$,$1); } 
  | TK_CT           {strcpy($$,$1); } 
;

postfix_expression
  : primary_expression
    { $$ = $1; }
  | postfix_expression TK_LSQB expression TK_RSQB
    { /* TODO */ }
  ;

unary_expression
  : postfix_expression
    { /* TODO */ }
  | TK_MI_OP primary_expression %prec TK_UMI {
        char *x;
        int size = asprintf(&x, "%s%s%s", "(- ",$2,")" );
        $$=x;
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
