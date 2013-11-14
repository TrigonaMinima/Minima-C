# define _XOPEN_SOURCE
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>

int main( int argc , char *argv[] )
{
  int i;
  char x[14],salt[3],word[9],str[30];
  if(argc != 2 || strlen(argv[1]) != 13)
  {
    printf( "bad input !!\n" );
    return 1;
  }
  salt[0]=argv[1][0];
  salt[1]=argv[1][1];
  FILE *f;
  f=fopen( "words" , "r" );
  while(!feof(f))
  {
    fgets( str,  sizeof(str), f);
    strncpy(word, str, 8);
    word[8]='\0';
    *index(word, '\n')='\0'; 
    strcpy( x , crypt( word , salt ) );
    //printf( "%s  " , word );
    //printf( "%s  " , x );
    if(strcmp( x , argv[1] ) == 0 )
      {
        printf( "%s" , word );
        break;
      } 
  }
  fclose(f);
  return 0;
}
