# include <iostream>
# include <math.h>

using namespace std;

int
Prime(int num)
{
	int i=2;
	while(i<(int (sqrt(num))+1))
	{
		if((num % i) == 0)
			return 0;
		i++;
	}
	return 1;
}

int
func(int A, int B)
{
	int n=1, pri, count=1;
	while(n>0)
	{
		pri = n*n + A*n + B;
		if(pri>0 && Prime(pri)==1)
			count++;
		else
			break;
		n++;
	}
	return count;
}


int
main()
{
	int i=0, a, b, p, maxprimes=0, maxprod, primearr[200];
	/*for(b=0; b<200; b++)
		primearr[b]=0;*/
	for(b=2; b<1000; b++)
	{
		if(Prime(b)==1)
		{
			primearr[i]=b;
			i++;
		}
	}
	//cout<<i<<"  "<<b<<endl;
	for(b=i-1; b>=0; b--)
	{
		for(a=-999; a<1000; a++)
		{
			p=func(a,primearr[b]);
			if(p>=maxprimes)
			{
				maxprimes = p;
				maxprod = a*primearr[b];
				//cout<<endl<<p<<"   "<<a<<"   "<<primearr[b]<<endl;
			}
		}
	}
	cout<<endl<<maxprimes<<"   "<<maxprod<<endl;
	return 0;
}
