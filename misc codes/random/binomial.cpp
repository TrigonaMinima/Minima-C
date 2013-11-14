/*
 * to find the binomial coefficient
 *
 * nCk = prod from i=0 to i=k ( (n-k+i)/i )
 *
 */
 
 
# include <iostream>

using namespace std;

int
bino(int n, int k)
{
	int i, value=1;
	if(k<0 || k>n)
		return 0;
	if(k>n-k)
		k=n-k;
	for(i=1; i<=k; i++)
	{
		value*= (n-k+i);
		value/= i;
	}
	cout<< value <<endl;
	return value;
}



int
main()
{
	int n=20, k=10, result;
	result = bino(n,k);
	cout<< result<<endl;
	return 0;
}
