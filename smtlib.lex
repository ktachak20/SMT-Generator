/* smtlib Lexer 
strdup -- It tries to allocate enough memory to hold the old string and 
copy the old string to the new string and return the new address.
*/
D     [0-9]
L     [a-zA-Z_]
%{
#include <stdio.h>
#include "smtlib.tab.h" /* need to include while using yacc*/
%}

%%

"if"          { /* yylval.string=strdup(yytext);*/ return(TK_IF); }
"else"        { /* yylval.string=strdup(yytext);*/ return(TK_ELSE); }

{L}({L}|{D})* { yylval.TK_identifier_t = strdup(yytext); return(TK_ID); }
{D}+          { yylval.TK_literal_t    = strdup(yytext); return(TK_CT); }

"["           { /* yylval.string=strdup(yytext);*/ return(TK_LSQB); }
"]"           { /* yylval.string=strdup(yytext);*/ return(TK_RSQB); }

","           { /* yylval.string=strdup(yytext);*/ return(TK_CMM); }
"=>"          { /* yylval.string=strdup(yytext);*/ return(TK_IMP_OP); }
"<="          { /* yylval.string=strdup(yytext);*/ return(TK_LE_OP); }
">="          { /* yylval.string=strdup(yytext);*/ return(TK_GE_OP); }
"=="          { /* yylval.string=strdup(yytext);*/ return(TK_EQ_OP); }
"!="          { /* yylval.string=strdup(yytext);*/ return(TK_NE_OP); }
"<"           { /* yylval.string=strdup(yytext);*/ return(TK_LT_OP); }
">"           { /* yylval.string=strdup(yytext);*/ return(TK_GT_OP); }

"="           { /* yylval.string=strdup(yytext);*/ return(TK_ASS_OP); }

"("           { /* yylval.string=strdup(yytext);*/ return(TK_LB); }
")"           { /* yylval.string=strdup(yytext);*/ return(TK_RB); }
"{"           { /* yylval.string=strdup(yytext);*/ return(TK_LP); }
"}"           { /* yylval.string=strdup(yytext);*/ return(TK_RP); }
";"           { /* yylval.string=strdup(yytext);*/ return(TK_ST_END); }

"-"           { /* yylval.string=strdup(yytext);*/ return(TK_MI_OP); }
"+"           { /* yylval.string=strdup(yytext);*/ return(TK_PL_OP); }
"*"           { /* yylval.string=strdup(yytext);*/ return(TK_MU_OP); }
"/"           { /* yylval.string=strdup(yytext);*/ return(TK_DI_OP); }
"%"           { /* yylval.string=strdup(yytext);*/ return(TK_MO_OP); }

"&&"          { /* yylval.string=strdup(yytext);*/ return(TK_AND_OP); }
"||"          { /* yylval.string=strdup(yytext);*/ return(TK_OR_OP); }
"!"           { /* yylval.string=strdup(yytext);*/ return(TK_NOT_OP); }
[ \t\v\n\f]		{ }
.			        { /* ignore bad characters */ }

%%

int yywrap()
{
  return (1);
}

