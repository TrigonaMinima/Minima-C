# include <fstream>
# include <iostream>
# include <stdlib.h>

using namespace std;

# define size 80

int
func(int a[][size][3])
{
	int i, j, k, alpha = 0;
	for(i=size-2; i>=0; i--)
	{
		a[i][size-1][0]+= a[i+1][size-1][0];
		a[size-1][i][0]+= a[size-1][i+1][0];
	}
	for(i=size-2; i>=0; i--)
	{
		for(j=size-2; j>=0; j--)
		{
			k=0;
			alpha = 0;
			while(k<3)
			{
				if(a[i+1][j][k] < a[i][j+1][k])//(num1 < num2)
					a[i][j][k]+= a[i+1][j][k] + alpha;
				else
					a[i][j][k]+= a[i][j+1][k] + alpha;
				alpha = 0;
				if(a[i][j][k]/100000000 > 0)
				{
					alpha = a[i][j][k]/100000000;
					a[i][j][k]%= 100000000;
				}
				k++;
			}
		}
	}
	return 0;
}


int
main()
{
	int i, j, k, p;
	char a[4];
	static int arr[size][size][3];
	fstream f("matrix.txt", ios::in);
	f.seekg(0);
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
			f.get(a, 5, ',');
			arr[i][j][0] = atoi(a);
			p = f.tellg();
			f.seekg(p+1);			
		}
	}
	f.close();
	func(arr);
	for(i=2; i>=0; i--)
		cout<<arr[0][0][i]<<" ";
	cout<<endl;
	return 0;
}
