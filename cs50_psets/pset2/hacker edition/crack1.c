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
  f=fopen( "words" , "r" );					//opening the file "words"
  while(!feof(f))
  {
    fgets( str,  sizeof(str), f);				//reads a line from the file
    if(strlen(str)<9)						//copying words of length<8 from str to word
    {
      for( i=0 ; i<strlen(str) ;i++ )
        word[i]=str[i];
      word[i]='\0';			      			//null terminating the word
    }
    else							//copying words with length>8 in str into word till the 8th position
    {
      for( i=0 ; i<8 ;i++ )
        word[i]=str[i];
      word[8]='\0';						//null terminating the word
    }
    *index(word, '\n')='\0';					//replacing "\n" with "\0" in words with length < 8
    strcpy( x , crypt( word , salt ) );				//encrypting the word from dictionary
    //printf( "%s  " , word );
    //printf( "%s  " , x );
    if(strcmp( x , argv[1] ) == 0 )
      {
        printf( "%s\n" , word );
        break;
      } 
  }
  fclose(f);
  return 0;
}
