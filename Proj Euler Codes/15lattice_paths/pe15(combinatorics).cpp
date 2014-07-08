# include <iostream>

using namespace std;


int
bino(int n, int k, int ar[])
{
	int i=1, j=0, l=0, beta, alpha=0, num[k], temp, sum;
	if(k<0 || k>n)
		return 0;
	if(k>n-k)
		k=n-k;
	for(l=0, i=1; l<k; l++, i++)
		num[l] = i;
	for(l=0, i=1; l<k; l++, i++)
		cout<<num[l]<<" ";
	cout<<endl;
	for(i=1; i<=k; i++)
	{
		temp = (n-k+i);
		for(l=k-1; l>=0; l--)
		{
			if(num[l]!=1)
			{
				if(temp % num[l] == 0 && temp >= num[l])
				{
					temp/= num[l];
					num[l] = 1;
				}
				if(num[l]>temp && num[l] % temp == 0)
				{
					num[l]/= temp;
					temp = 1;
				}
			}
		}
				
		j=0;
		while(j < 5)
		{
			beta = ar[j]*temp + alpha;
			alpha = beta/10000;
			ar[j] = beta%10000;
			j++;
		}
		cout<<temp<<" ";
	}
	cout<< endl;
	for(l=0, i=1; l<k; l++, i++)
		cout<<num[l]<<" ";	
	cout<< endl;		
	return 0;
}




int
main()
{
	int n=20,c=20;
	int a[5]={1,0,0,0,0};
	bino(2*20, 20, a);
	for(n=4; n>=0; n--)
		cout<<a[n]<<" ";
	return 0;
}


