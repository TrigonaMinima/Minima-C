# include <iostream>
using namespace std;

int main()
{
	int arr[20], j=2, t=3, i, m=0, alpha=0, beta ;
	for(i=1; i<20; i++)
		arr[i]=0;
	arr[0]=1;
	while(t<=1001)
	{
		arr[0]+= 4*t*t - 6*t + 6;
		for(i=0; i<9; i++)
		{
			arr[i+1]+= arr[i]/10;
			arr[i]%=10;
		}
		t+=2;
	}
	for(i=19; i>=0; i--)
		cout<<arr[i];
	cout<<endl;
	return 0;
}
