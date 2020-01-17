#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <smtlib.tab.h>
#include <smtlibp.h>


#define MAXVARS 100


extern int  yylex();
extern int  yyparse();
extern FILE *yyin;

char        *ofile;
char        *vfile;
int         varcount = 0;
DATA_expr_t *VAR_P_LIST[MAXVARS]; /* variable names and associated type */


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
      if( !strcmp(VAR_P_LIST[i]->body, node->body) ) // Variable Name is already in list
      {
        if( VAR_P_LIST[i]->type != node->type )
        {
            printf("\nTypeError: Redefining a variable to different type!\n");
            exit(-1);
        }
        return;
      }
      printf("DEBUG: no error FN_varcheck 2.%d.1\n", i);
    }
  } 
  /* VAR_P_LIST[i] = var; */
  printf("DEBUG: no error FN_varcheck 3\n");
  VAR_P_LIST[i] = FN_mk_node(node->body, node->type);
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
      vmap = FN_get_var_type(VAR_P_LIST[i]);
      printf("DEBUG: no error in FN_vardef 0.1\n");
      fprintf(vfile_h, "%s\n", vmap);
      printf("DEBUG: no error in FN_vardef 0.2\n");
      NODE_free(VAR_P_LIST[i]);
      printf("DEBUG: no error in FN_vardef 0.3\n");
      i++;
  }
  printf("DEBUG: no error in FN_vardef 1\n");
  vmap = FN_get_var_type(VAR_P_LIST[i]);
  printf("DEBUG: no error in FN_vardef 2\n");
  fprintf(vfile_h, "%s\n", vmap);
  printf("DEBUG: no error in FN_vardef 3\n");
  NODE_free(VAR_P_LIST[i]);
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

void FN_write_node_to_file(DATA_expr_t *node)
{
    printf("DEBUG: no error FN_write_node_to_file 1\n");
    FILE *fname_h = fopen(ofile, "w");
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
