# include <stdio.h>
# include <string.h>
int i, crd[16];
char num[16];

int convert()
{
	int j,c=0;
	for(j=0; j<strlen(num); j++)
		crd[j]=num[j]-48;
	i=j;
	for(j=0; j<i; j++)
	{
		if(crd[j]<10 && crd[j]>=0)
			c++;
		else
			c--;
	}
	return c;
}

int check()
{
	int j, sum=0;
	for(j=0; j<i; j++)
	{
		if(j%2 ==0)
			sum+=crd[j];
		else
			sum+= ((crd[j]*2)%10)+((crd[j]*2)/10);
	}
	if(sum%10 == 0 )
		return 0;
	else
		return 1; 
}



int main()
{
	int b;
	printf("Enter your credit card no. : ");
	scanf("%s", num);
	while(convert()!=i)
	{
		printf("Retry : ");
		scanf("%s", num);
	}
	if(check()==0)
	{
		if(crd[0]==3 && i==15 && (crd[1]==4 || crd[1]==7))
			printf("\nAMEX\n");
		else if(crd[0]==5 && i==16 && (crd[1]==1 || crd[1]==2 || crd[1]==3 || crd[1]==4 || crd[1]==5))
			printf("\nMASTERCARD\n");
		else if(crd[0]==4 && (i==16 || i==13))
			printf("\nVISA\n");
	}
	else
		printf("\nINVALID\n");
	return 0;
}


