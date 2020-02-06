#include <stdio.h>
#include <time.h>

extern int FN_smtlib_parse( const char * );


int main( int argc, char **argv )
{
  if( argc != 2 )
  {
    printf( "usage: %s infile\n", argv[0] );
    return -1;
  }

  clock_t begin = clock();
  int ret = FN_smtlib_parse( argv[1] );
  clock_t end = clock();

  if( ret == 0 )
  {
      printf("Time: %f\n", (double)(end - begin)/CLOCKS_PER_SEC);
      return ret;
  }
  return ret;
}
