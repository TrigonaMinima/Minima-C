#include <stdio.h>

int main()
{
	char ch;
	while((ch=getc(stdin))!='\n')
	{
		//printf("You entered: %d. Converted it to %d.\n", ch, ch-48);
		printf("%d\n", ch);
	}
	return 0;
}
