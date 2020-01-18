#ifndef SMTLIB_H
#define SMTLIB_H

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

#define PRINT_DEBUG(fmt, ...) \
    printf("DEBUG: " #fmt "\n", ##__VA_ARGS__)


typedef struct _DATA_expr_t { char *body; int type; } DATA_expr_t;


extern int  FN_smtlib_parse( const char * );
int         FN_vardef( void );
void        FN_varcheck( DATA_expr_t * );
/* char        *FN_mk_vdecl(char *, char *); */
DATA_expr_t *FN_mk_node( const char *, int );
void        FN_write_node_to_file( DATA_expr_t * );
DATA_expr_t *FN_gen_assert( DATA_expr_t *stmt );
DATA_expr_t *FN_gen_impl( DATA_expr_t *ncond,
                          DATA_expr_t *nbranch1,
                          DATA_expr_t *nbranch2 );
DATA_expr_t *FN_gen_conjunc( DATA_expr_t *nstart,
                             DATA_expr_t *nend );
DATA_expr_t *FN_gen_exp( DATA_expr_t *nleft,
                         DATA_expr_t *nright,
                         int op_t );
DATA_expr_t *FN_gen_exp_unary( DATA_expr_t *, int );
char        *FN_get_var_type( DATA_expr_t * );

#endif /* #endif SMTLIB_H */
