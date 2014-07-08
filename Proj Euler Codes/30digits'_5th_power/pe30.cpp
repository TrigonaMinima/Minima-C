# include <iostream>
# include <math.h>
using namespace std;

int powers[10];

int
five(int n)
{
	return pow(n, 5);
}


int fifthpower(int num)
{
	int b=num, sum=0;
	while(b > 0)
	{
		sum+= powers[b%10];
		b/= 10;
	}
	if(sum == num)
		return 1;
	else
		return 0;
}	


int main()
{
	int a=200000, c, b=0, alpha=0 ;
	static int arr[20];
	//for(b=0; b<100; b++)
	//	arr[b]=0;
	for(b=0; b<10; b++)
		powers[b] = five(b);
	b=0;
	
	while(a>1000)
	{
		c=fifthpower(a);
		if(c==1)
		{
			arr[0]+= a;
			b=0;
			alpha = 0;
			while(b<19)
			{
				alpha = arr[b]/10;
				arr[b]%= 10;
				arr[b+1]+= alpha;
				b++;
			}
		}
		a--;
	}
	for(b=19; b>=0; b--)
		cout<<arr[b]<<" ";
	return 0;
}
