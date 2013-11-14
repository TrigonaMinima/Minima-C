/*
 * insertion sort
 * O(n^2)
 */

# include <stdio.h>

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
	insort(data, size);
	printf("\n");
	for(i=0; i<size; i++)
		printf( "%d  ", data[i]);
	return 0;
}
