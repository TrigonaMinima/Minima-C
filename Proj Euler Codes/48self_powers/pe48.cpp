# include <iostream>
# include <unistd.h>
using namespace std;

int pow[650], total[650], i;

int power(int num)
{
	int alpha=0, beta, c=num ;
	for(i=1; i<650; i++)
		pow[i]=0;
	pow[0]=1;
	while(c>0)
	{
		for(i=0; i<650; i++)
		{
			beta = pow[i]*num + alpha;
			alpha = beta/100000;
			pow[i] = beta%100000;
		}
		c--;
	}
	return 0;	
}

int sumpowers()
{
	for(i=0; i<649; i++)
	{
		total[i]+= pow[i];
		total[i+1]+= total[i]/100000;
		total[i]%= 100000;
	}
	return 0;
}

int main()
{
	int a=1000;
	total[0]=1;
	while(a>1)
	{
		power(a);
		sumpowers();
		a--;
	}
	for(i=649; i>=0; i--)
		cout<<total[i]<<" ";
	cout<<endl;
	return 0;
}
