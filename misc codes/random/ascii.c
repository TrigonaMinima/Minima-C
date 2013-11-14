# include <stdio.h>
# include <stdlib.h>


int
main()
{
	int a;
	for(a=0; a<300; a++)
	{
		printf("%c \t %d\n", a, a);
		//sleep(0.5);
	}	
	return 0;
}
