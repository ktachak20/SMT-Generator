int main( int argc, char **argv )
{
  if( argc != 3 )
  {
    printf( "usage: %s infile outfile\n", argv[0] );
    return -1;
  }

  callSMTLIBparser( argv[1], argv[2] );

  return 0;
}
