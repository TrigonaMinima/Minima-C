// SJF non preemptive

# include <stdio.h>
# include <string.h>

const int n = 10;

int sort(char p[n][5], int a[n], int size)
{
	int i, j, temp;
	char str[5];
	for(i=0; i<size; i++)
	{
		for(j=i; 	j<size; j++)
		{
			if(a[i] > a[j])
			{
				temp = a[i];
				strcpy(str, p[i]);
				a[i] = a[j];
				strcpy(p[i], p[j]);
				a[j] = temp;
				strcpy(p[j], str);
			}
		}
	}
	return 0;
}


display(char p[n][5], int a[n], int size)
{
	int i;
	float wait=0;
	printf("\n\n");
	for(i=0; i<size; i++)
		printf(" ----");
	printf("\n|");
	for(i=0; i<size; i++)
	{
		printf(" %2s |", p[i]);
		if(i>0)
			a[i] += a[i-1];
	}
	printf("\n");
	for(i=0; i<size; i++)
		printf(" ----");
	printf("\n00   ");
	for(i=0; i<size; i++)
		printf("%02d   ", a[i]);
	printf("\n");

	for(i=0; i<size-1; i++)
		wait += a[i];

	printf("\nAverage Waiting Time = %f ms", wait/size);
	printf("\nAverage Turnaround Time = %f ms\n", (wait+a[i])/size);

	return 0;
}

int main()
{
	FILE *f;
	int t[n], i=0;
	char p[10][5];
	f = fopen("process.txt", "r");
	printf("  PROCESSES  BURST\n");
	while(!feof(f))
	{
		fscanf(f, "%s %d", p[i], &t[i]);
		printf("%6s         %02d\n", p[i], t[i]);
		i++;
	}

	sort(p, t, i);
	display(p, t, i);

	return 0;
}