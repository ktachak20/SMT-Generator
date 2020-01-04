int main( int argc, char **argv )
{
  if( argc != 2 )
  {
    printf( "usage: %s infile\n", argv[0] );
    return -1;
  }

  callSMTLIBparser( argv[1] );

  return 0;
}
