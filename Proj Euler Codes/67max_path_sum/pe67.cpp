# include <fstream>
# include <iostream>

using namespace std;

int main()
{
	static int ar[100][100];
	char s;
	int i=0,j=0;
	fstream f("triangle.txt" , ios::in );
	f.seekg(0);
	while(f)
	{
		for(j=0; j<=i; j++)
			f>>ar[i][j];
		i++;
	}
	f.close();
	i=98;
	while(i>=0)
	{
		for(j=0; j<=i; j++)
		{
			if(ar[i+1][j] > ar[i+1][j+1])
				ar[i][j]+= ar[i+1][j];
			else
				ar[i][j]+= ar[i+1][j+1];
		}
		i--;
	}
	cout<<ar[0][0]<<endl;
	return 0;
}
