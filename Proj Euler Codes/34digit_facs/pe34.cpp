# include <iostream>
using namespace std;

static int facs[10];

int
facto(int n)
{
	int prod=1;
	for(int i=2; i<=n; i++)
		prod*= i;
	cout<<prod<<endl;
	return prod;
}


int
digitfacs(int num)
{
	int b=num, sum=0;
	while(b > 0)
	{
		sum+= facs[b%10];
		b/= 10;
	}
	if(sum == num)
		return 1;
	else
		return 0;
}	


int
main()
{
	int a=100000, c, b, alpha=0 ;
	static int arr[4];
	for(b=0; b<10; b++)
		facs[b] = facto(b);
	b=0;
	while(a>10)
	{
		if(digitfacs(a)==1)
		{
			arr[0]+= a;
			b=0;
			alpha = 0;
			while(b<4)
			{
				alpha = arr[b]/100;
				arr[b]%= 100;
				arr[b+1]+= alpha;
				b++;
			}
		}
		a--;
	}
	for(b=3; b>=0; b--)
		cout<<arr[b]<<" ";
	cout<<"\n";
	return 0;
}
