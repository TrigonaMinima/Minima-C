/* form forum
The solving procedure for this problem can be optimized after running a slower brute force method and observing the results. 1479 is the first number to produce a chain of length 60. Since 0 and 1 have the same factorial value of 1, 4079 also has a chain of length 60. There are no other four digit combinations that result in a chain of length 60. There are no five digit results. The first six digit result is 223479. Thus all permutations of this number have a chain of length 60. There are no other six digit results. Doing the math we get: 4! + 3*3! + 6!/2 = 402
*/


# include <iostream>

using namespace std;

static int a[10]; 

int
fac(int d)
{
	int prod = 1;
	if(d==0)
		return 0;
	while(d>0)
	{
		prod*= d;
		d--;
	}
	return prod;
}

int
digits(int d)
{
	int c=0;
	while(d!=0)
	{
		c+= a[d%10];
		d/= 10;
	}
	//cout<<c<<" ";
	return c;
}


int
func(int num)
{
	int c=1;
	while(1)
	{
		if(c>62)
			break;
		if(num==145 || num==1)
			break;
		if(num==871 || num==872 || num==169)
		{
			if(num==169)
				c+= 2;
			else
				c+= 1;
			break;
		}
		num = digits(num);
		c++;
	}
	return c;

}


int
main()
{
	int i, count=0;
	a[0] = 1;
	for(i=1; i<10; i++)
		a[i] = fac(i);
	/*for(i=0; i<10; i++)
		cout<<a[i]<<"  ";
	cout<<endl;*/
	i = 999999;
	while(i>1)
	{
		if(func(i)==60)
			count++;
		//cout<<count<<"  ";
		i--;
	}
	cout<<count<<endl;
	return 0;
}
