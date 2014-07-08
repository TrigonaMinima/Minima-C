# include <iostream>

using namespace std;

int
bino(int n, int k, int *a)
{
	int i, value=1;
	if(k<0 || k>n)
		return 0;
	if(k>n-k)
		k=n-k;
	for(i=1; i<=k; i++)
	{
		value*= (n-k+i);
		value/= i;
		if(value>1000000)
			break;
	}
	if(value>1000000)
		(*a)++;
	return 0;
}



int
main()
{
	int n, k, count=0;
	for(n=1; n<=100; n++)
	{
		for(k=1; k<=n; k++)
			bino(n, k, &count);
	}
	cout<< count<<endl;
	return 0;
}
