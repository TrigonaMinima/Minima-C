/*
 * merge sort
 * O(n*lg(n))
 */


# include <stdio.h>

int
merge(int a[], int b[], int c[], int s)
{
	int i=0, j=0, k=0;
	
	while(i<s/2 && j<(s-s/2))
	{
		if(a[i]<=b[j])
		{
			c[k]=a[i];
			i++;
		}
		else
		{
			c[k]=b[j];
			j++;
		}
		k++;
	}
	for(; k<s; k++)
	{
		if(i==s/2)
		{
			c[k]=b[j];
			j++;
		}
		else
		{
			c[k]=a[i];
			i++;
		}
	}
	return 0;
}



int
sort(int array[], int a)
{
	int i, j, s1=a/2, s2=a-s1, ar1[s1], ar2[s2];
	if(s1>0 && s2>0)
	{
		for(i=0; i<s1; i++)
			ar1[i]=array[i];
		for(j=0; j<s2; j++)
			ar2[j]=array[j+i];
		
	/*	for(i=0; i<s1; i++)
			printf("%d ", ar1[i]);
		printf("\t");
		for(j=0; j<s2; j++)
			printf("%d ", ar2[j]);
		printf("\n");*/
		
		sort(ar1, s1);
		sort(ar2, s2);
		merge (ar1, ar2, array, s1+s2);
	}
	return 0;
}



int
main(int argc, char *argv[])
{
	int i, size;
	size = atoi(argv[1]);
	int  data[size];
	//printf("enter the size of array : ");
	//scanf("%d", &size);
	printf("\nenter the elements-\n");
	for(i=0; i<size; i++)
		scanf( "%d", &data[i]);
	for(i=0; i<size; i++)
		printf( "%d  ", data[i]);
	sort(data, size);
	printf("\n");
	for(i=0; i<size; i++)
		printf( "%d  ", data[i]);
	return 0;
}
