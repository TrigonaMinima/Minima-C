# include <iostream>
using namespace std;
int sq[10]= {0,1,4,9,16,25,36,49,64,81};

int sqsum(int num)
{
	int sum=0, b;
	while(num>0)
	{
		b=num%10;
		sum+= sq[b];
		num = (num-b)/10;
	}
	return sum;
}

int main()
{
	int i=10000000, a=0, c=0;
	while(i>0)
	{
		a=i;
		while(a)
		{
			a=sqsum(a);
			if(a==89)
			{
				c++;
				break;
			}
			if(a==1)
				break;
			//cout<<"sdfsgs"<<endl;
		}
		i--;
	}
	cout<<c<<endl;
	return 0;
}
 
