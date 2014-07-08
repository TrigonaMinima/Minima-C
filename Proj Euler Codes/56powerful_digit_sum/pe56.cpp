/*
*I used brute force, ie a from 2 and b from 1
*From forum-
*Solving, 90^99=10^k, k=99log90, so 90^99 contains int(99log90)+1=194 digits.
*Working on the principle that the average digit is 5 (a uniform distribution of digits), we would expect the sum of digits in 90^99 to be 5*194=970.
*Similarly, 90^90 contains int(90log90)+1=176 digits, with an expected sum is 880; and 99^99 contains int(99log99)+1=198 digits, with an expected sum is 990.
*Note how quickly our expected sum becomes smaller by comparing 90^99 (970) with 90^90 (880).
*Based on this I used (in my view) an excessively modest/safe search, starting with a=90 and b=90.
*/


# include <iostream>
using namespace std;
int pow[202];

int sum(int a, int b)
{
	int alpha=0, beta, sum=0, i ;
	for(i=1; i<202; i++)
		pow[i]=0;
	pow[0]=1;
	while(b>0)
	{
		for(i=0; i<202; i++)
		{
			beta = pow[i]*a + alpha;
			alpha = beta/10;
			pow[i] = beta%10;
		}
		b--;
	}
	for(i=0; i<202; i++)
		sum+= pow[i];
	return sum;	
}


int main()
{
	int i, j, total=0, max=0 ;
	for(i=90; i<100; i++)
	{
		for(j=90; j<100; j++)
		{
			if((total=sum(i, j)) > max)
				max = total;
		}
	}
	cout<< max<<endl;
	return 0;
}
