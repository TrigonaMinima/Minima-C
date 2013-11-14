# include <stdio.h>
# include <string.h>
int main()
{
	int a[20], i;
	char b[20];
//	scanf("%s", b);
	fgets( b,  sizeof(b), stdin);
	for(i=0; b[i]!='\0'; i++)
	{
		//a[i]=b[i];
		//printf("%c", b[i]);
		printf("%d  ", b[i]);
	}
	return 0;
}
