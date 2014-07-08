# include <iostream>
using namespace std;

int main()
{
	int alpha=0, beta;
	long a[1000], b[1000], c[1000], d=2, i;
	for(i=1; i<1000; i++)
	{
		a[i]=0;
		b[i]=0;
		c[i]=0;
	}
	a[0]=1;
	b[0]=1;
	while(!c[999])
	{
		for(i=0; i<1000; i++)
		{
			beta = a[i] + b[i] + alpha;
			alpha = beta/10;
			c[i] = beta%10;
			b[i] = a[i];
			a[i] = c[i];
		}
	d++;
	}
	cout<<d<<endl;
	for(i=999; i>=0; i--)
		cout<<c[i]<<" ";
	cout<<endl;
	return 0;
}
