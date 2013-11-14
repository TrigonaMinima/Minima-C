
int
lattice(int a[][limit][5], int s, int b[])
{
	int i, j, k, alpha=0;
	for(i=s-1; i>=0; i--)
	{
		a[i][s-1][0] = 1;
		a[s-1][i][0] = 1;
	}
	for(i=s-2; i>=0; i--)
	{
		for(j=s-2; j>=0; j--)
		{
			k=0;
			alpha = 0;
			while(k<5)
			{
				a[i][j][k] = a[i+1][j][k] + a[i][j+1][k] + alpha;
				alpha = 0;
				if(a[i][j][k]/1000 > 0)
				{
					alpha = a[i][j][k]/1000;
					a[i][j][k]%= 1000;
				}
				k++;
			}
		}
	}
	for(i=s-1; i>=0; i--)
	{
		cout<<"[ ";
		for(j=s-1; j>=0; j--)
		{
			cout<<"( ";
			for(k=4; k>=0; k--)
				cout<<a[i][j][k]<<" ";
			cout<<") ";
		}
		cout<<"] "<<endl;
	}
	return 0;
}
