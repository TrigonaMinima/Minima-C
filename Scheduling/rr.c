// Round Robin

# include <stdio.h>
# include <string.h>

const int n = 10;

display(char p[n][5], int a[n], int size, int q)
{
	int i=0, flag=0, j=0, k=0, temp=0;
	float wait=0;
	int rr[30][2];
	while(flag != size)
	{
		flag = 0;
		if(i == size)
			i=0;
		if(a[i] > q)
		{
			a[i] -= q;
			rr[j][0] = q;
			rr[j][1] = i;
			wait += q*(size-temp-1);
			j++;
		}
		else if(a[i] > 0)
		{
			rr[j][0] = a[i];
			rr[j][1] = i;
			wait += a[i]*(size-temp-1);
			a[i] = 0;
			j++;
		}
		i++;
		for(k=0; k<size; k++)
		{
			if(a[k] == 0)
				flag ++;
		}
		temp = flag;
	}

	printf("\n\n");
	for(i=0; i<j; i++)
		printf(" ----");
	printf("\n|");
	for(i=0; i<j; i++)
	{
		printf(" %2s |", p[rr[i][1]]);
		if(i>0)
			rr[i][0] += rr[i-1][0];
	}
	printf("\n");
	for(i=0; i<j; i++)
		printf(" ----");
	printf("\n00   ");
	for(i=0; i<j; i++)
		printf("%02d   ", rr[i][0]);
	printf("\n");

	// for(i=0; i<size-1; i++)
	// 	wait += rr[i][0];

	printf("\nAverage Waiting Time = %f ms", wait/size);
	printf("\nAverage Turnaround Time = %f ms\n", (wait+rr[i-1][0])/size);

	return 0;
}

int main()
{
	FILE *f;
	int t[n], i=0, q=0;
	char p[10][5];
	f = fopen("process.txt", "r");
	printf("  PROCESSES  BURST\n");
	while(!feof(f))
	{
		fscanf(f, "%s %d", p[i], &t[i]);
		printf("%6s         %02d\n", p[i], t[i]);
		i++;
	}

	printf("\nGive the time quanta: ");
	scanf("%d", &q);

	display(p, t, i, q);

	return 0;
}