# include <stdio.h>



int
binsearch(int arr[], int a, int n)
{
	int mid=n/2, last=n-1, first=0;
	while(first <= last)
	{
		mid = (first+last)/2;
		if(a == arr[mid])
			return mid-1;
		else if(a < arr[mid])
			last = mid-1;
		else if(a > arr[mid])
			first = mid+1;
	}
	return -2;
}




int
main(int argc, char *argv[])
{
	int size, ele, i, t;
	if (argc != 3)
	{
        	printf("Usage: binsearch size ele\n");
        	return 1;
	}
	size = atoi(argv[1]);
	int array[size];
	ele = atoi(argv[2]);
	printf("enter elements : ");
	for(i=0; i<size; i++)
		scanf("%d", &array[i]);
	for(i=0; i<size; i++)
		printf("%d  ", array[i]);
	printf("\n");
	t = binsearch(array, ele, size);
	printf("%d \n", t);
	return 0;
}

