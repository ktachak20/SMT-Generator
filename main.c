#include <stdio.h>

extern int FN_smtlib_parse( const char * );


int main( int argc, char **argv )
{
  if( argc != 2 )
  {
    printf( "usage: %s infile\n", argv[0] );
    return -1;
  }

  return FN_smtlib_parse( argv[1] );
}
