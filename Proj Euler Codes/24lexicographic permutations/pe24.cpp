/*
 * pe-24
 */


# include <iostream>

using namespace std;

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
		temp=array[p+i];
		array[p+i]=array[s-1-i];
		array[s-1-i]=temp;
	}
	return 0;
}



int
perm(int a[], int size)
{
	int i, j=size, k=1, l=0, m=6, n;
	while(m>0)
	{
		
		j=-1;
		for(i=0; i<size; i++)
		{
			if(a[i] < a[i+1])
				j=i+1;
		}
		if(k==1000000)
		{
			for(i=0; i<size; i++)
				cout<< a[i];
			cout<<endl;
			break;
		}
		for(i=j; i<size; i++)
		{
			if(a[j-1] < a[i])
				l = i;
		}
		swap(a, l, j-1);
		rev(a, j, size);
		k++;
	}
	return 0;
}


int
main()
{
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	perm(a, 10);
	return 0;
}
