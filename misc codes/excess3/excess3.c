/*
 * Excess-3 codes
 */
# include <stdio.h>

int
BCD(int a, int ar[4])
{
	int i=0;
	while(a != 0)
	{
		ar[i] = a%2;
		a/= 2;
		i++;
	}
	return 0;
}

 
int
main()
{
	char c;
	int i, bcd[4], num[3];
	FILE *f;
	f=fopen( "junktext.txt" , "r" );
	//while((c=fgetc(stdin)) != '\n')
	while(!feof(f))
	{
		c=fgetc(f);
		if(c=='\n')
		{
			printf("\n");
			continue;
		}
		i=c;
		i+= 3;
		if(i>=127)
			i = i%127 + 32;
		//c=i;
		num[0] = i/100;
		num[1] = (i%100 - i%10)/10;
		num[2] =i%10 ;
		//printf("\n%c %d %c\n", c, i, i);
		i=0;
		if(num[0] == 0)
			i=1;
		while(i<3)
		{
			bcd[1] = 0;
			bcd[0] = 0;
			bcd[2] = 0;
			bcd[3] = 0;
			BCD(num[i], bcd);
			printf("%d%d%d%d", bcd[3], bcd[2], bcd[1], bcd[0]);
			i++;
		}
	}
	fclose(f);
	printf("\n");
	return 0;
}
