# define _XOPEN_SOURCE
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>

int main( int argc , char *argv[] )
{
 	int i;
 	char x[14],salt[3],word[9];
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
		i=0;
		while((word[i]=getc(f))!='\n'&&i<8)				// Reading 1 character at a time until either the length reaches 8 or '\n' is encountered.
			i++;
		if(word[i]!='\n')
			while(getc(f)!='\n')					// Taking the file pointer till the end of line above if the word length reaches 8 first.
				;
		word[i]='\0';							// Null terminating the string.
		strcpy( x , crypt( word , salt ) );
		if(strcmp( x , argv[1] ) == 0 )
		{
			printf( "%s\n" , word );
			break;
		} 
	}
	fclose(f);
	return 0;
}
