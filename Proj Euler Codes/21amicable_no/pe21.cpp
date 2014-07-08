# include <iostream>
using namespace std;

int factors(int num)
{
	int i, sum=0 ;
	for(i=1; i<=(num/2); i++)
	{
		if(num%i == 0)
			sum+=i;
	}
	return sum;
}


int main()
{
	int a, j, i=10000, di, ddi, aminums[15], abort=0, sum[15], alpha=0;
	for(a=0; a<15; a++)
	{
		aminums[a]=0;
		sum[a]=0;
	}
	a=0;
	while(i>5)
	{
		for(j=0; j<15; j++)
		{	
			if( i == aminums[j] )
			{
				abort=0 ;
				break;
			}
			else 
				abort++	;
		}
		if(abort)
		{
			di = factors(i);
			ddi = factors(di);
			//cout<<i<<"  "<<di<<"  "<<ddi<<endl;
			if( (di != i) && (ddi == i) )
			{
				aminums[a] = i;
				aminums[a+1] = di;
				a+=2;
			}
		}
		i--;
	}
	for(j=0; j<15; j++)
	{
		cout<<aminums[j]<<" ";
		alpha+= aminums[j];
	}
	cout<<endl<<alpha<<endl;
	
/*	a=0;
	while(a<15)
	{
		sum[0]+= aminums[a];
		for(j=0; j<14; j++)
		{
			sum[j+1]+= sum[j]/10000;
			sum[j] = sum[j]%10000;
		}
		a++;
	}
	cout<<endl;
	for(j=14; j>=0; j--)
		cout<<sum[j]<<" "; */
	return 0;
}
