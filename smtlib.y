/* smtlib Parser */
/* Objectives:
    1. generate file containing variables declared. (DONE)
    2. generate two files, infile.smt and infile.var, from a single source file. (DONE)
*/

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define YYDEBUG 1

#include <smtlib.h>

extern int  yylex();
extern int  yyparse();
extern FILE *yyin;
extern void yyerror( const char * );
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
    {
    #ifdef DEBUG
        PRINT_DEBUG("no error primary");
    #endif
        $$ = FN_mk_node($1, TK_ID);
    }
  | TK_CT
    {
    #ifdef DEBUG
        PRINT_DEBUG("no error primary");
    #endif
        $$ = FN_mk_node($1, TK_CT);
    }
  ;

postfix_expression: primary_expression
                    { 
                    #ifdef DEBUG
                        PRINT_DEBUG("no error postfix 1");
                    #endif
                        $$ = $1;
                    }
                  | postfix_expression TK_LSQB expression TK_RSQB
                    {
                    #ifdef DEBUG
                        PRINT_DEBUG("no error postfix 2");
                    #endif
                        char *tmp;
                  
                        if( $1->type == TK_ID )
                        {
                          /* Check variable is already defined and set. */
                          $1->type = NT_ARR_EXP;
                          FN_varcheck($1);
                        }

                    #ifdef DEBUG
                        PRINT_DEBUG("no error postfix 3");
                    #endif
                  
                        asprintf(&tmp, "(select %s %s)", $1->body, $3->body);
                        $$ = FN_mk_node(tmp, NT_PST_EXP);
                        NODE_free($1); NODE_free($3);
                    #ifdef DEBUG
                        PRINT_DEBUG("no error postfix 4");
                    #endif
                    }
                  ;

unary_operator
  : TK_MI_OP
    {
    #ifdef DEBUG
        PRINT_DEBUG("no error unary_op");
    #endif
        $$ = FN_mk_node("-", TK_MI_OP);
    }
  ;

unary_expression
  : postfix_expression
    {
    #ifdef DEBUG
        PRINT_DEBUG("no error unary_exp 1");
    #endif
        if( $1->type == TK_ID ) FN_varcheck($1);
        $$ = $1;
    }
  | unary_operator unary_expression
    {
    #ifdef DEBUG
        PRINT_DEBUG("no error unary_exp 2");
    #endif
        $$ = FN_gen_exp_unary($2, $1->type);
        NODE_free($1);
    #ifdef DEBUG
        PRINT_DEBUG("no error unary_exp 3");
    #endif
    }
  ;

operator: TK_PL_OP
          { 
          #ifdef DEBUG
              PRINT_DEBUG("no error op 1");
          #endif
              char *op; asprintf(&op, "+");
              $$ = FN_mk_node(op, TK_PL_OP);
          }
        | TK_MI_OP
          { 
          #ifdef DEBUG
              PRINT_DEBUG("no error op 2");
          #endif
              char *op; asprintf(&op, "-");
              $$ = FN_mk_node(op, TK_PL_OP);
          }
        | TK_MU_OP
          { 
          #ifdef DEBUG
              PRINT_DEBUG("no error op 3");
          #endif
              char *op; asprintf(&op, "*");
              $$ = FN_mk_node(op, TK_PL_OP);
          }
        | TK_DI_OP
          { 
          #ifdef DEBUG
              PRINT_DEBUG("no error op 4");
          #endif
              char *op; asprintf(&op, "div");
              $$ = FN_mk_node(op, TK_PL_OP);
          }
        | TK_MO_OP
          { 
          #ifdef DEBUG
              PRINT_DEBUG("no error op 5");
          #endif
              char *op; asprintf(&op, "mod");
              $$ = FN_mk_node(op, TK_PL_OP);
          }
        ;

expression: unary_expression
            {
            #ifdef DEBUG
                PRINT_DEBUG("no error exp1");
            #endif
                $$ = $1;
            }
          | expression operator expression
            {
            #ifdef DEBUG
                PRINT_DEBUG("no error exp2");
            #endif
                $$ = FN_gen_exp($1, $3, $2->type);
                NODE_free($2);
            #ifdef DEBUG
                PRINT_DEBUG("no error exp2");
            #endif
            }
          ;

assignment_expression: unary_expression TK_ASS_OP expression
                       {
                       #ifdef DEBUG
                           PRINT_DEBUG("no error assn_exp");
                       #endif
                           char *exp;

                           asprintf(&exp, "(= %s %s)", $1->body, $3->body);
                           $$ = FN_mk_node(exp, NT_ASSN_EXP);

                           NODE_free($1); NODE_free($3);

                       #ifdef DEBUG
                           PRINT_DEBUG("no error assn_exp2");
                       #endif
                       } 
                     | TK_LB assignment_expression TK_RB
                       {
                       #ifdef DEBUG
                           PRINT_DEBUG("no error assn_exp");
                       #endif
                           $$ = $2;
                       }
                     ;

relational_operator: TK_LT_OP
                     {
                     #ifdef DEBUG
                         PRINT_DEBUG("no error rel_op1");
                     #endif
                         char *op; asprintf(&op, "<");
                         $$ = FN_mk_node(op, TK_LT_OP);
                     }
                   | TK_GT_OP
                     {
                     #ifdef DEBUG
                         PRINT_DEBUG("no error rel_op2");
                     #endif
                         char *op; asprintf(&op, ">");
                         $$ = FN_mk_node(op, TK_GT_OP);
                     }
                   | TK_LE_OP
                     {
                     #ifdef DEBUG
                         PRINT_DEBUG("no error rel_op3");
                     #endif
                         char *op; asprintf(&op, "<=");
                         $$ = FN_mk_node(op, TK_LE_OP);
                     }
                   | TK_GE_OP
                     {
                     #ifdef DEBUG
                         PRINT_DEBUG("no error rel_op4");
                     #endif
                         char *op; asprintf(&op, ">=");
                         $$ = FN_mk_node(op, TK_GE_OP);
                     }
                   | TK_EQ_OP
                     {
                     #ifdef DEBUG
                         PRINT_DEBUG("no error rel_op5");
                     #endif
                         char *op; asprintf(&op, "=");
                         $$ = FN_mk_node(op, TK_GE_OP);
                     }
                   | TK_NE_OP
                     {
                     #ifdef DEBUG
                         PRINT_DEBUG("no error rel_op6");
                     #endif
                         char *op; asprintf(&op, "!=");
                         $$ = FN_mk_node(op, TK_NE_OP);
                     }
                   | TK_ASS_OP
                     {
                     #ifdef DEBUG
                         PRINT_DEBUG("no error rel_op7");
                     #endif
                         char *op; asprintf(&op, "=");
                         $$ = FN_mk_node(op, TK_NE_OP);
                     }
                   ;

primary_conditional_expression
  : expression relational_operator expression
    {
    #ifdef DEBUG
        PRINT_DEBUG("no error prim_cond_exp1");
    #endif
        $$ = FN_gen_exp($1, $3, $2->type); NODE_free($2);
    }
  ;     
        
logical_operator: TK_AND_OP
                  {
                  #ifdef DEBUG
                      PRINT_DEBUG("no error log_op1");
                  #endif
                      $$ = FN_mk_node("and", TK_AND_OP);
                  }
                | TK_OR_OP
                  {
                  #ifdef DEBUG
                      PRINT_DEBUG("no error log_op1");
                  #endif
                      $$ = FN_mk_node("or", TK_OR_OP);
                  }
                | TK_IMP_OP
                  {
                  #ifdef DEBUG
                      PRINT_DEBUG("no error log_op1");
                  #endif
                      $$ = FN_mk_node("=>", TK_IMP_OP);
                  }
                | TK_EQ_OP
                  {
                  #ifdef DEBUG
                      PRINT_DEBUG("no error log_op1");
                  #endif
                      $$ = FN_mk_node("=", TK_EQ_OP);
                  }
                ;

conditional_expression: primary_conditional_expression
                        {
                        #ifdef DEBUG
                            PRINT_DEBUG("no error cond_exp1");
                        #endif
                            $$ = $1;
                        }
                      | TK_NOT_OP conditional_expression
                        {
                        #ifdef DEBUG
                            PRINT_DEBUG("no error cond_exp2");
                        #endif
                            $$ = FN_gen_exp_unary($2, TK_NOT_OP);
                        }
                      | conditional_expression logical_operator conditional_expression
                        {
                        #ifdef DEBUG
                            PRINT_DEBUG("no error cond_exp3");
                        #endif
                            $$ = FN_gen_exp($1, $3, $2->type); NODE_free($2);
                        }
                      | TK_LB conditional_expression TK_RB
                        {
                        #ifdef DEBUG
                            PRINT_DEBUG("no error cond_exp4");
                        #endif
                            $$ = $2;
                        }
                      ;

assignment_statement: assignment_expression TK_ST_END
                      {
                      #ifdef DEBUG
                        PRINT_DEBUG("no error assn_st1");
                      #endif
                        $$ = $1;
                      }
                    ;

assignments: assignment_statement
             {
             #ifdef DEBUG
                PRINT_DEBUG("no error assn1");
             #endif
                $$ = $1;
             }
           | assignment_statement assignments
             {
             #ifdef DEBUG
                PRINT_DEBUG("no error assn2");
             #endif
                $$ = FN_gen_conjunc($1, $2);
             }
           ;

mixed_statements: assignments
                  {
                  #ifdef DEBUG
                    PRINT_DEBUG("no error mix_st1");
                  #endif
                    $$ = $1;
                  }
                | decision
                  {
                  #ifdef DEBUG
                    PRINT_DEBUG("no error mix_st2");
                  #endif
                    $$ = $1;
                  }
                | assignments mixed_statements
                  {
                  #ifdef DEBUG
                    PRINT_DEBUG("no error mix_st3");
                  #endif
                    $$ = FN_gen_conjunc($1, $2);
                  }
                | decision mixed_statements
                  {
                  #ifdef DEBUG
                    PRINT_DEBUG("no error mix_st4");
                  #endif
                    $$ = FN_gen_conjunc($1, $2);
                  }
                ;

innerblock: assignment_statement
            {
            #ifdef DEBUG
                PRINT_DEBUG(" innblock1");
            #endif
                $$ = $1;
            }
          | decision
            {
            #ifdef DEBUG
                PRINT_DEBUG("no error innblock2");
            #endif
                $$ = $1;
            }
          | TK_LP mixed_statements TK_RP
            {
            #ifdef DEBUG
                PRINT_DEBUG("no error innblock3");
            #endif
                $$ = $2;
            }
          ;

decision: TK_IF conditional_expression innerblock 
          {
          #ifdef DEBUG
            PRINT_DEBUG("no error deci1");
          #endif
            $$ = FN_gen_impl($2, $3, NULL);
          }
        | TK_IF conditional_expression innerblock TK_ELSE innerblock
          {
          #ifdef DEBUG
            PRINT_DEBUG("no error deci2");
          #endif
            $$ = FN_gen_impl($2, $3, $5);
          }
        ;

assertions: assignment_statement
            {
            #ifdef DEBUG
                PRINT_DEBUG("no error asst1");
            #endif
                $$ = FN_gen_assert($1);
            }
          | assignment_statement assertions
            {
            #ifdef DEBUG
                PRINT_DEBUG("no error asst2");
            #endif
                char *assrt;
                asprintf(&assrt, "(assert %s)\n%s", $1->body, $2->body);
                NODE_free($1); NODE_free($2);
                $$ = FN_mk_node(assrt, NT_ASSRT);
            }
          | decision
            {
            #ifdef DEBUG
                PRINT_DEBUG("no error asst3");
            #endif
                $$ = FN_gen_assert($1);
            }
          | decision assertions
            {
            #ifdef DEBUG
                PRINT_DEBUG("no error asst4");
            #endif
                char *assrt;
                asprintf(&assrt, "(assert %s)\n%s", $1->body, $2->body);
                NODE_free($1); NODE_free($2);
                $$ = FN_mk_node(assrt, NT_ASSRT);
            }
          ;

smtlib: assertions
        {
        #ifdef DEBUG
            PRINT_DEBUG("no error smtlib");
        #endif
            FN_vardef(); FN_write_node_to_file($1); NODE_free($1);
        }
      ;

%%

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
}

