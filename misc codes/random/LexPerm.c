/*
 * Lexicographic permutations (generalised)
 */

# include <stdio.h>

int
swap(int arr[], int a, int b)
{
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
	return 0;
}


int
rev(int array[], int p, int s)
{
	int i, temp;
	for(i=0; i<(s-p+1)/2; i++)
	{
		swap(array, array[p+i], array[s-1-i]);
		/*temp=array[p+i];
		array[p+i]=array[s-1-i];
		array[s-1-i]=temp;*/
	}
	return 0;
}



int
insort(int arr[], int s)
{
	int i, j, key;
	for(i=1; i<s; i++)
	{
		key = arr[i];
		j = i-1;
		while(j >= 0 && key < arr[j])
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	return 0;
}


int
perm(int a[], int size)
{
	int i, j=size, k, l=0, m=6, n;
	while(m>0)
	{
		for(i=0; i<size; i++)
			printf("%d ", a[i]);
		printf("\n");
		j=-1;
		for(i=0; i<size; i++)
		{
			if(a[i] < a[i+1])
				j=i+1;
		}
		if(j==-1)
			break;
		for(i=j; i<size; i++)
		{
			if(a[j-1] < a[i])
				l = i;
		}
		swap(a, l, j-1);
		rev(a, j, size);
	}
	return 0;
}


int
main(int agrc, char *argv[])
{
	int i=0, ar[3];
	while(argv[1][i] != '\0')
	{
		ar[i] = (argv[1][i]-48);
		i++;
	}
	insort(ar, i);
	perm(ar, i);
	return 0;
}
