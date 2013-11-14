# include <iostream>
using namespace std;
#define limit 900

int fac(int prod[], int a)
{
	int i, t, alpha=0, beta=0 ;
	t=3;

	while(t<=a)
	{
		for(i=0; i<limit; i++)
		{
			beta = prod[i]*t+alpha;
			alpha = beta/1000;
			prod[i] = beta%1000;
		}
	t++;
	}
	for(i=limit-1; i>=0; i--)
		cout<<prod[i]<<" ";
	cout<<endl; 
	return 0;
}

int
main()
{	
	int prod[limit], i;
	for(i=0; i<limit; i++)
		prod[i]=0; 
	prod[0]=2;
	int num = 1000;
	fac(prod, num);
	return 0;
}
