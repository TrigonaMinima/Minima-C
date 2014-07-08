# include <iostream>
using namespace std;
int main()
{
	int power[320], a, alpha=0, beta=0, i=2, sum=0 ;
	for(a=1; a<320; a++)
		power[a]=0;
	power[0]=2;
	while(i<=1000)
	{
		for(a=0; a<320; a++)
		{
			beta = power[a]*2 + alpha;
			alpha = beta/10;
			power[a] = beta%10;
		}
	i++;
	}
	for(a=319; a>=0; a--)
		cout<<power[a]<<" ";
	cout<<endl;
	for(a=319; a>=0; a--)
		sum+=power[a];
	cout<<sum<<endl;
	return 0;
}
