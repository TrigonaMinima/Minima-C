# include <iostream>
# include <math.h>
using namespace std;

int main()
{
	int i, t, alpha=0, beta=0 ;
	long int prod[200], sum=0;
	t=3;
	for(i=0; i<200; i++)
		prod[i]=0;
	prod[0]=2;
	while(t<=100)
	{
		for(i=0; i<200; i++)
		{
			beta = prod[i]*t+alpha;
			alpha = beta/10;
			prod[i] = beta%10;
		}
	t++;
	}
	for(i=199; i>=0; i--)
		cout<<prod[i]<<" ";
	cout<<endl; 
	for(i=0; i<200; i++)
		sum+= prod[i];
	cout<<sum;
	cout<<endl;
	return 0;
}
 
