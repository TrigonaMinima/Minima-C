/*
As a starter, based on the relation
   a^2+b^2 = c^2
If both a and b are even, c will also be even and P (the perimeter) will be even.
If both a and b are odd, c will be even and P will be even.
If one is even and the other is odd, c will be odd and P will again be even.
Therefore, only even values of P need to be checked.
*/





# include <iostream>
using namespace std;

int main()
{
	int p=3, a, b, c, maxp=2, size=0, i, j, k, l=0;
	while(p<=1000)
	{
		if(p%2==0)
		{
			l=0;
			for(i=1; i<p; i++)
			{
				for(j=i+1; j<p; j++)
				{
					k = p-i-j;
					if((i*i + j*j == k*k))
						l++;
				}
			}
			if(l>size)
			{
				size=l;
				maxp=p;
			}
		}
		p++;	
	}
	cout<<maxp<<"  "<<size<<endl;
	return 0;
}
