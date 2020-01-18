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

#ifdef DEBUG
  PRINT_DEBUG("no error FN_varcheck 1");
#endif

  if( varcount > 0 )
  {
    for( ; i < varcount ; i++ )
    {

#ifdef DEBUG
      PRINT_DEBUG("no error FN_varcheck 2.%d.0", i);
#endif

      if( !strcmp(VAR_P_LIST[i]->body, node->body) ) // Variable Name is already in list
      {
        if( VAR_P_LIST[i]->type != node->type )
        {
            printf("\nTypeError: Redefining a variable \"%s\" to different type!\n", VAR_P_LIST[i]->body);
            exit(-1);
        }
        return;
      }

#ifdef DEBUG
      PRINT_DEBUG("no error FN_varcheck 2.%d.1", i);
#endif

    }
  } 

#ifdef DEBUG
  PRINT_DEBUG("no error FN_varcheck 3");
#endif

  VAR_P_LIST[i] = FN_mk_node(node->body, node->type);
  varcount++;

#ifdef DEBUG
  PRINT_DEBUG("no error FN_varcheck 4");
#endif

  return;
}

char* FN_get_var_type(DATA_expr_t *v)
{
    char *type;

#ifdef DEBUG
    PRINT_DEBUG("no error FN_get_var_type 1");
#endif

    switch(v->type)
    {

#ifdef DEBUG
    PRINT_DEBUG("no error FN_get_var_type 1");
#endif

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

#ifdef DEBUG
    PRINT_DEBUG("no error FN_get_var_type 1");
#endif

    return type;
}

int FN_vardef()
{
  int i = 0;
  char *vmap;

  FILE *vfile_h = fopen(vfile, "w");

#ifdef DEBUG
  PRINT_DEBUG("no error FN_vardef, variable file %s", vfile);
#endif

  while( i<varcount-1 )
  {

#ifdef DEBUG
      PRINT_DEBUG("no error FN_vardef 0.%d.0", i);
#endif

      vmap = FN_get_var_type(VAR_P_LIST[i]);

#ifdef DEBUG
      PRINT_DEBUG("no error FN_vardef 0.%d.1", i);
#endif

      fprintf(vfile_h, "%s\n", vmap);

#ifdef DEBUG
      PRINT_DEBUG("no error FN_vardef 0.%d.2", i);
#endif

      NODE_free(VAR_P_LIST[i]);

#ifdef DEBUG
      PRINT_DEBUG("no error FN_vardef 0.%d.3", i);
#endif

      i++;
  }

#ifdef DEBUG
  PRINT_DEBUG("no error in FN_vardef 1");
#endif

  vmap = FN_get_var_type(VAR_P_LIST[i]);

#ifdef DEBUG
  PRINT_DEBUG("no error in FN_vardef 2");
#endif

  fprintf(vfile_h, "%s\n", vmap);

#ifdef DEBUG
  PRINT_DEBUG("no error in FN_vardef 3");
#endif

  NODE_free(VAR_P_LIST[i]);

#ifdef DEBUG
  PRINT_DEBUG("no error in FN_vardef 4");
#endif

  return 1;
}

DATA_expr_t* FN_mk_node(const char *s, int type)
{

#ifdef DEBUG
  PRINT_DEBUG("no error in FN_mk_node 1");
#endif

  DATA_expr_t *node = malloc(sizeof(DATA_expr_t));
  asprintf(&(node->body), "%s", s);
  node->type = type;

#ifdef DEBUG
  PRINT_DEBUG("no error in FN_mk_node 2");
#endif

  return node;
}

/** TODO: to be removed
char* FN_mk_vdecl(char *v, char *v_t)
{
  char *decl;

#ifdef DEBUG
  PRINT_DEBUG("no error in FN_mk_decl 1");
#endif

  asprintf(&decl, "(declare-const %s %s)\n", v, v_t);

#ifdef DEBUG
  PRINT_DEBUG("no error in FN_mk_node 2");
#endif

  return decl;
}
*/

DATA_expr_t* FN_gen_exp(DATA_expr_t *nleft, DATA_expr_t *nright, int op_t)
{
    char *exp;

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_mk_node 1");
#endif

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

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_mk_node 2");
#endif


    NODE_free(nleft); NODE_free(nright);

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_mk_node 3");
#endif

    return FN_mk_node(exp, NT_EXP);
}

DATA_expr_t* FN_gen_conjunc(DATA_expr_t *nstart, DATA_expr_t *nend)
{
    char *assn;

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_gen_conjunc 1");
#endif

    asprintf(&assn, "(and %s %s)", nstart->body, nend->body);
    NODE_free(nstart); NODE_free(nend);

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_gen_conjunc 2");
#endif

    return FN_mk_node(assn, NT_CONJ);
}

DATA_expr_t* FN_gen_impl(DATA_expr_t *ncond, DATA_expr_t *nbranch1, DATA_expr_t *nbranch2)
{
    char *impl;

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_gen_impl 1");
#endif

    if( nbranch2 == NULL )
    {

#ifdef DEBUG
        PRINT_DEBUG("no error in FN_gen_impl 2");
#endif

        asprintf(&impl, "(ite %s %s (= 1 1))", ncond->body, nbranch1->body);

#ifdef DEBUG
        PRINT_DEBUG("no error in FN_gen_impl 3");
#endif

        NODE_free(ncond); NODE_free(nbranch1);

#ifdef DEBUG
        PRINT_DEBUG("no error in FN_gen_impl 4");
#endif

    }
    else
    {

#ifdef DEBUG
        PRINT_DEBUG("no error in FN_gen_impl 5");
#endif

        asprintf(&impl, "(ite %s %s %s)", ncond->body, nbranch1->body, nbranch2->body);

#ifdef DEBUG
        PRINT_DEBUG("no error in FN_gen_impl 6");
#endif

        NODE_free(ncond); NODE_free(nbranch1); NODE_free(nbranch2);

#ifdef DEBUG
        PRINT_DEBUG("no error in FN_gen_impl 7");
#endif

    }

#ifdef DEBUG
        PRINT_DEBUG("no error in FN_gen_impl 8");
#endif

    return FN_mk_node(impl, NT_IMPL);
}

DATA_expr_t* FN_gen_assert(DATA_expr_t *stmt)
{
    char *assert;

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_gen_assert 1");
#endif

    asprintf(&assert, "(assert %s)", stmt->body);

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_gen_assert 2");
#endif

    NODE_free(stmt);

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_gen_assert 3");
#endif

    return FN_mk_node(assert, NT_ASSRT);
}

void FN_write_node_to_file(DATA_expr_t *node)
{

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_gen_assert 1");
#endif

    FILE *fname_h = fopen(ofile, "w");

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_gen_assert 2");
#endif

    fprintf(fname_h, "%s", node->body);
}

DATA_expr_t* FN_gen_exp_unary( DATA_expr_t *arg, int op_t)
{
    char *exp;

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_gen_assert 1");
#endif

    switch(op_t)
    {
    case TK_MI_OP:
        asprintf(&exp, "(* -1 %s)", arg->body);
        break;
    default:
        printf("\nInvalid Syntax: operator no recognized!\n");
        break;
    }

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_gen_assert 2");
#endif

    NODE_free(arg);

#ifdef DEBUG
    PRINT_DEBUG("no error in FN_gen_assert 3");
#endif

    return FN_mk_node(exp, NT_EXP);
}
